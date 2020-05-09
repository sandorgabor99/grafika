/*
 * move.c
 *
 
 */

#include <math.h>
#include "model.h"
#include "callbacks.h"
#include "move.h"

int movingWhichkatona = 0;

void move_katona(World* world) {
	if(movingWhichkatona == 0)
	{
		if(abs((int)(camera.position.x - world->katona1.position.x)) + abs((int)(camera.position.z - world->katona1.position.z)) <
				abs((int)(camera.position.x - world->katona2.position.x)) + abs((int)(camera.position.z - world->katona2.position.z)))
		{
			movingWhichkatona = 1;
		}
		else {
			movingWhichkatona = 2;
		}
	}

	if(abs(camera.position.x) < 170 && abs(camera.position.z) < 170)
	{
		switch (movingWhichkatona) {
			case 1:
				if (abs((int)(camera.position.x - world->katona1.position.x)) < 50 && abs((int)(camera.position.z - world->katona1.position.z)) < 50 && camera.position.y < 150)
				{
					world->katona1.position.x = camera.position.x + 10;
					world->katona1.position.z = camera.position.z + 10;
				}

				break;
			case 2:
				if (abs((int)(camera.position.x - world->katona2.position.x)) < 50 && abs((int)(camera.position.z - world->katona2.position.z)) < 50 && camera.position.y < 150)
				{
					world->katona2.position.x = camera.position.x + 10;
					world->katona2.position.z = camera.position.z + 10;
				}

				break;
		}
	}
}
