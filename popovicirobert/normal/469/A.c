#include <stdio.h>
#include <stdlib.h>
int v[101];
int main()
{
    int i,nr,n1,n2,n;
    scanf("%d%d" ,&n,&n1);
    for(i=0;i<n1;i++){
        scanf("%d" ,&nr);
        v[nr]=1;
    }
    scanf("%d" ,&n2);
    for(i=0;i<n2;i++){
        scanf("%d" ,&nr);
        v[nr]=1;
    }
    i=1;
    while(i<=n&&v[i]==1)
        i++;
    if(i==n+1)
        printf("I become the guy.");
    else
        printf("Oh, my keyboard!");
    return 0;
}