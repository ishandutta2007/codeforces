#include <stdio.h>
#include <math.h>
#include<string.h>

int main()
{
    long int a[30],b[30],c[30];
    long int d,e,f,x,y,z;
    scanf("%ld %ld",&d,&e);
    for(x=0;x<30;x++)
    {
        a[x]=0;
        b[x]=0;
        c[x]=0;
    }
    x=0;
    z=d;
    y=0;
    while(z>0)
    {
        a[x]=z%3;
        x++;
        z=(z-z%3)/3;
    }
    y=x==0?0:x-1;
    z=e;
    x=0;
    while(z>0)
    {
        c[x]=z%3;
        x++;
        z=(z-z%3)/3;
    }
    y=x-1>y?x-1:y;
    for(x=0;x<=y;x++)
    {
        if(c[x]<a[x])
        {
            b[x]=c[x]+3-a[x];
        }
        else
        {
            b[x]=c[x]-a[x];
        }
    }
    z=0;
    for(x=y;x>=0;x--)
    {
        z=z*3+b[x];
    }
    printf("%ld",z);
    return 0;
}