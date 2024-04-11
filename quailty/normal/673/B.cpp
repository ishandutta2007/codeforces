#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int mi=1,mx=n;
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        mi=max(mi,u);
        mx=min(mx,v);
    }
    printf("%d",max(0,mx-mi));
    return 0;
}