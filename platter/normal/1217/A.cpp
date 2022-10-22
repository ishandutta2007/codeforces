#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
    int power,brain,point;
    scanf("%d %d %d\n", &power, &brain, &point);
    int x=power-brain+point;
    if (x<0) {
        printf("0\n");
    }
    if (x>=0)
    printf("%d\n", min((x+1)/2,point+1));
    }
    return 0;
}