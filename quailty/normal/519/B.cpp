#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int xa=0,xb=0,xc=0;
    int a,b,c;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        xa^=a;
    }
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&b);
        xb^=b;
    }
    for(int i=1;i<=n-2;i++)
    {
        scanf("%d",&c);
        xc^=c;
    }
    printf("%d\n%d",xa^xb,xb^xc);
    return 0;
}