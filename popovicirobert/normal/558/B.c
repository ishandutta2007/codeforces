#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000001
int prim[MAXN],ult[MAXN],vf[MAXN];
int main()
{
    int n,st,dr,max,nr,i;
    scanf("%d" ,&n);
    for(i=0;i<n;i++){
        scanf("%d" ,&nr);
        if(prim[nr]==0){
            prim[nr]=ult[nr]=i+1;
        }
        else
            ult[nr]=i+1;
        vf[nr]++;
    }
    max=0;
    for(i=1;i<=MAXN;i++)
       if(vf[i]>max){
            max=vf[i];
            st=prim[i];
            dr=ult[i];
       }
       else
          if(vf[i]==max&&ult[i]-prim[i]+1<dr-st+1){
              st=prim[i];
              dr=ult[i];
          }
    printf("%d %d" ,st,dr);
    return 0;
}