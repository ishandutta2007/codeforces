#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,mod;
int cnt[505];
char s[505];
bool vis[505][505];
ll dp[505][505];
queue<int>x[505],y[505];
void bfs()
{
    for(int i=0;i<=n;i++)
    {
        while(!x[i].empty())x[i].pop();
        while(!y[i].empty())x[i].pop();
    }
    x[0].push(0);
    y[0].push(0);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        while(!x[i].empty())
        {
            int tx=x[i].front();
            int ty=y[i].front();
            x[i].pop();
            y[i].pop();
            if(cnt[i]==0)
            {
                x[i+1].push(tx);
                y[i+1].push(ty);
            }
            else if(cnt[i]==1)
            {
                if(ty>=1)
                {
                    if(!vis[tx+1][ty-1])
                    {
                        x[i+1].push(tx+1);
                        y[i+1].push(ty-1);
                        vis[tx+1][ty-1]=1;
                    }
                    dp[tx+1][ty-1]=(dp[tx+1][ty-1]+(ty*dp[tx][ty])%mod)%mod;
                }
                if(!vis[tx][ty+1])
                {
                    x[i+1].push(tx);
                    y[i+1].push(ty+1);
                    vis[tx][ty+1]=1;
                }
                dp[tx][ty+1]=(dp[tx][ty+1]+((n-m-tx-ty)*dp[tx][ty])%mod)%mod;
            }
            else
            {
                if(ty>=2)
                {
                    if(!vis[tx+2][ty-2])
                    {
                        x[i+1].push(tx+2);
                        y[i+1].push(ty-2);
                        vis[tx+2][ty-2]=1;
                    }
                    ll temp=(ty*(ty-1)/2)%mod;
                    dp[tx+2][ty-2]=(dp[tx+2][ty-2]+(temp*dp[tx][ty])%mod)%mod;
                }

                if(ty>=1)
                {
                    if(!vis[tx+1][ty])
                    {
                        x[i+1].push(tx+1);
                        y[i+1].push(ty);
                        vis[tx+1][ty]=1;
                    }
                    ll temp=(ty*(n-m-tx-ty))%mod;
                    dp[tx+1][ty]=(dp[tx+1][ty]+(temp*dp[tx][ty])%mod)%mod;
                }
                if(!vis[tx][ty+2])
                {
                    x[i+1].push(tx);
                    y[i+1].push(ty+2);
                    vis[tx][ty+2]=1;
                }
                ll temp=((n-m-tx-ty)*(n-m-tx-ty-1)/2)%mod;
                dp[tx][ty+2]=(dp[tx][ty+2]+(temp*dp[tx][ty])%mod)%mod;
            }
        }
    }
}
int main()
{

    while(scanf("%d%d%d",&n,&m,&mod)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            scanf("%s",&s);
            for(int i=0;i<n;i++)
            {
                cnt[i]+=s[i]-'0';
            }
        }
        for(int i=0;i<n;i++)
        {
            cnt[i]=2-cnt[i];
        }
        bfs();
        /*
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        */
        printf("%I64d\n",dp[n-m][0]);
    }
    return 0;
}