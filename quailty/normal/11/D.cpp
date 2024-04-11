#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=19;
int g[MAXN][MAXN];
ll dp[1<<MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        g[u][v]=g[v][u]=1;
    }
    for(int i=0;i<n;i++)
        dp[1<<i][i]=1;
    for(int mask=1;mask<(1<<n);mask++)
    {
        int mx=0;
        for(int i=0;i<n;i++)
            if(mask&(1<<i))mx=i;
        for(int i=0;i<=mx;i++)
        {
            if(~mask&(1<<i))continue;
            for(int j=0;j<=mx;j++)
            {
                if(mask&(1<<j) || !g[i][j])continue;
                dp[mask|(1<<j)][j]+=dp[mask][i];
            }
        }
    }
    ll res=0;
    for(int mask=1;mask<(1<<n);mask++)
    {
        int mx=0;
        for(int i=0;i<n;i++)
            if(mask&(1<<i))mx=i;
        for(int i=0;i<=mx;i++)
        {
            if(~mask&(1<<i) || !g[mx][i])continue;
            res+=dp[mask][i];
        }
    }
    printf("%I64d",(res-m)/2);
    return 0;
}