#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double db;
const int MAXN=1005;
const db INF=1e100;
const db PI=acos(-1.0);
ll sqr(ll x)
{
    return x*x;
}
struct Circle
{
    ll x,y,r;
    bool operator < (const Circle &t)const
    {
        return r<t.r;
    }
    db area()const
    {
        return PI*r*r;
    }
}c[MAXN];
vector<int> e[MAXN];
db dp[MAXN][2][2];
void dfs(int u)
{
    db sum[2][2];
    for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
            sum[j][k]=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs(v);
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                sum[j][k]+=dp[v][j][k];
    }
    for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
            dp[u][j][k]=-INF;
    for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
        {
            dp[u][j][k]=max(dp[u][j][k],sum[j^1][k]+(1-2*j)*c[u].area());
            dp[u][j][k]=max(dp[u][j][k],sum[j][k^1]+(1-2*k)*c[u].area());
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&c[i].x,&c[i].y,&c[i].r);
    sort(c+1,c+n+1);
    vector<int> rt(n+1,1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(sqr(c[i].x-c[j].x)+sqr(c[i].y-c[j].y)<=sqr(c[i].r-c[j].r))
            {
                e[j].push_back(i);
                rt[i]=0;
                break;
            }
    db res=0;
    for(int i=1;i<=n;i++)if(rt[i])
    {
        dfs(i);
        res+=dp[i][0][0];
    }
    printf("%.12f",(double)res);
    return 0;
}