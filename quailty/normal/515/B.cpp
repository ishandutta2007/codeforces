#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool hb[105],hg[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int b;
    scanf("%d",&b);
    for(int i=1;i<=b;i++)
    {
        int x;
        scanf("%d",&x);
        hb[x]=1;
    }
    int g;
    scanf("%d",&g);
    for(int i=1;i<=g;i++)
    {
        int y;
        scanf("%d",&y);
        hg[y]=1;
    }
    for(int cnt=1;cnt<=1000;cnt++)
        for(int k=0;k<m*n;k++)
        {
            if(hb[k%n]||hg[k%m])
            {
                hb[k%n]=1;
                hg[k%m]=1;
            }
        }
    bool isok=1;
    for(int i=0;i<n;i++)
        if(!hb[i])isok=0;
    for(int i=0;i<m;i++)
        if(!hg[i])isok=0;
    if(isok)printf("Yes");
    else printf("No");
    return 0;
}