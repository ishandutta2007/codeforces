#include <stdio.h>
#include <stdlib.h>
int vf[10];
int main()
{
    int i,nr;
    for(i=0;i<6;i++){
        scanf("%d" ,&nr);
        vf[nr]++;
    }
    i=0;
    while(i<10&&vf[i]<4)
        i++;
    if(i==10)
        printf("Alien");
    else{
        i=0;
        while(i<10&&vf[i]!=2)
            i++;
        if(i==10){
            i=0;
            while(i<10&&vf[i]<6)
                i++;
            if(i==10)
              printf("Bear");
            else
              printf("Elephant");
        }
        else
            printf("Elephant");
    }
    return 0;
}