#include <stdio.h>
#include <stdlib.h>
int v[500000],v1[500000];
int main()
{
    int n,i,con;
    scanf("%d" ,&n);
    for(i=0;i<n;i++)
        scanf("%d" ,&v[i]);
    v1[0]=v[0];
    for(i=1;i<n;i++)
        v1[i]=v1[i-1]+v[i];
    if(v1[n-1]%2==1)
        printf("0");
    else{
        con=0;
        for(i=0;i<n-1;i++)
            if(v1[i]==v1[n-1]-v1[i])
              con++;
        printf("%d" ,con);
    }
    return 0;
}