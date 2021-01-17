#ifndef _JEWELGROUPANIM_H_
#define _JEWELGROUPANIM_H_

#include "Config.h"
#include "Animation.h"

#include <memory>

#include "go_window.h"
#include "go_image.h"

class JewelGroupAnim
{
public:
    void loadResources (GoSDL::Window * w)
    {
        imgGems[0].setWindowAndPath(w, MEDIA_DIR "/gemWhite.png");
        imgGems[1].setWindowAndPath(w, MEDIA_DIR "/gemRed.png");
        imgGems[2].setWindowAndPath(w, MEDIA_DIR "/gemPurple.png");
        imgGems[3].setWindowAndPath(w, MEDIA_DIR "/gemOrange.png");
        imgGems[4].setWindowAndPath(w, MEDIA_DIR "/gemGreen.png");
        imgGems[5].setWindowAndPath(w, MEDIA_DIR "/gemYellow.png");
        imgGems[6].setWindowAndPath(w, MEDIA_DIR "/gemBlue.png");

        for (int i = 0; i < 7; ++i)
        {
            posX[i] = 800 / 2 - (65 * 7) / 2 + i * 65;
        }

        animationCurrentStep = 0;
        animationTotalSteps = 30;
        posFinalY = 265;
    }

    void draw(){

        // Step the animation
        if(animationCurrentStep < 7 * 5 + animationTotalSteps) {
            ++animationCurrentStep;
        }

        // Draw the jewels
        for(int i = 0; i < 7; ++i)
        {
            int composedStep = animationCurrentStep - i * 5;
            if(composedStep < 0) continue;

            if(composedStep < animationTotalSteps){
                imgGems[i].draw(posX[i],
                                   Animacion::easeOutCubic(
                                       (float) composedStep,
                                       600.f,
                                       (float) posFinalY - 600.f,
                                       (float) animationTotalSteps),
                                   2.f);
            }else{
                imgGems[i].draw(posX[i], posFinalY, 2);
            }
        }
    }

private:
    GoSDL::Image imgGems[7];

    int posX[7], posFinalY;

    int animationCurrentStep;
    int animationTotalSteps;

};


#endif /* _JEWELGROUPANIM_H_ */
