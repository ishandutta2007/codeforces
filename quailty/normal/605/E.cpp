#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=1005;
const db INF=1e10;
db p[MAXN][MAXN];
db fp[MAXN],tp[MAXN],dp[MAXN];
bool vis[MAXN];
void Dijkstra(int n)
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=INF;
        tp[i]=0;
        fp[i]=1;
        vis[i]=0;
    }
    dp[n]=0;
    for(int j=1;j<=n;j++)
    {
        int k=-1;
        db Min=INF;
        for(int i=1;i<=n;i++)
            if(!vis[i] && dp[i]<Min)
            {
                Min=dp[i];
                k=i;
            }
        if(k==-1)break;
        vis[k]=1;
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                tp[i]+=fp[i]*p[i][k]*dp[k];
                fp[i]*=(1-p[i][k]);
                if(fp[i]<1)
                    dp[i]=(tp[i]+1)/(1-fp[i]);
            }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%lf",&p[i][j]);
            p[i][j]/=100;
        }
    Dijkstra(n);
    printf("%.10f\n",dp[1]);
    return 0;
}