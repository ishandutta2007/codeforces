#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,p1,p2;
    scanf("%i %i %i",&n,&p1,&p2);
    int sk[n];
    p1--;
    p2--;
    for(int i = 0;i<n;i++){
        scanf("%i",&sk[i]);
    }
    int truth = 1;
    int sim;
    for(int b = 0;b<n;b++){
        scanf("%i",&sim);
        if(sim != sk[b]){
            if(b < p1 || b > p2){
                truth =0 ;
            }
        }
    }
    if(truth == 1){
        printf("TRUTH");
    }
    else{
        printf("LIE");
    }
    return 0;
}