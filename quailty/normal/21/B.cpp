#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[2],b[2],c[2];
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int ty[2];
    for(int i=0;i<2;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int g=abs(gcd(a[i],gcd(b[i],c[i])));
        if(g)a[i]/=g,b[i]/=g,c[i]/=g;
        if(a[i]<0)a[i]=-a[i],b[i]=-b[i],c[i]=-c[i];
        if(a[i]==0 && b[i]<0)b[i]=-b[i],c[i]=-c[i];
    }
    for(int i=0;i<2;i++)
    {
        if(a[i]==0 && b[i]==0)ty[i]=(c[i]==0 ? 1 : -1);
        else ty[i]=0;
    }
    if(ty[0]<0 || ty[1]<0)printf("0");
    else if(ty[0]==0 && ty[1]==0)
    {
        if(a[0]*b[1]-a[1]*b[0]==0)printf("%d",(c[0]==c[1] ? -1 : 0));
        else printf("1");
    }
    else printf("-1");
    return 0;
}