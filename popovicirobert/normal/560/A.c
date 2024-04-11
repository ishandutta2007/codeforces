#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,nr,flag;
    scanf("%d" ,&n);
    flag=0;
    for(i=0;i<n;i++){
        scanf("%d" ,&nr);
        if(nr==1)
            flag=1;
    }
    if(flag==1)
        printf("-1");
    else
        printf("1");
    return 0;
}