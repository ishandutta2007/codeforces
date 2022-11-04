#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2005;
int a[MAXN],cnt[MAXN];
bool check(int n,int m)
{
    int mx=0,mi=MAXN;
    for(int i=1;i<=m;i++)
    {
        mx=max(mx,cnt[i]);
        mi=min(mi,cnt[i]);
    }
    return mi==n/m;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[min(a[i],m+1)]++;
    }
    int res=0;
    while(!check(n,m))
    {
        int u=1;
        if(cnt[m+1])u=m+1;
        else for(int i=1;i<=m;i++)
            if(cnt[i]>cnt[u])u=i;
        int v=1;
        for(int i=1;i<=m;i++)
            if(cnt[i]<cnt[v])v=i;
        cnt[u]--;
        cnt[v]++;
        for(int i=1;i<=n;i++)
            if(min(a[i],m+1)==u)
            {
                a[i]=v;
                break;
            }
        res++;
    }
    int mi=MAXN;
    for(int i=1;i<=m;i++)
        mi=min(mi,cnt[i]);
    printf("%d %d\n",mi,res);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}