#include <cstdio>

using namespace std;

int h1,h2,a,b;

int main(){
    scanf("%d %d %d %d",&h1,&h2,&a,&b);

    int day = 0;
    while(1){
        h1+=a*8;
        if(h1>=h2){
            printf("%d",day);
            break;
        }
        day++;
        //printf("Day %d:%d",day,h1);
        h1-=b*12;
        h1+=a*4;
        if(b>=a){
            printf("-1");
            return 0;
        }
        //printf("Night %d:%d",day,h1);

    }

}