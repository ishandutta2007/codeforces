#include <stdio.h>
#include <math.h>
#include<string.h>

int main()
{
    long int a[101];
    long int x,y,z,b,c,d;
    scanf("%ld",&b);
    for(x=1;x<=100;x++)
    {
        a[x]=0;
    }
    for(x=1;x<=b;x++)
    {
        scanf("%ld",&c);
        a[c]=x;
    }
    for(x=1;x<=b;x++)
    {
        printf("%ld ",a[x]);
    }
    return 0;
}