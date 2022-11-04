#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p[3],t[2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        scanf("%d",&p[i]);
    for(int i=0;i<2;i++)
        scanf("%d",&t[i]);
    int res=0,la=0;
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(i)
        {
            int g=l-la;
            if(g>=t[0]+t[1])res+=t[0]*p[0]+t[1]*p[1]+(g-t[0]-t[1])*p[2];
            else if(g>=t[0])res+=t[0]*p[0]+(g-t[0])*p[1];
            else res+=g*p[0];
        }
        res+=(r-l)*p[0];
        la=r;
    }
    printf("%d\n",res);
    return 0;
}