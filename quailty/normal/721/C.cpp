#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5005;
const int INF=0x3f3f3f3f;
vector<pair<int,int> >e[MAXN],re[MAXN];
int dp[MAXN][MAXN],deg[MAXN],vis[MAXN];
void pre(int n)
{
    queue<int>q;
    q.push(n);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].first;
            q.push(v);
        }
    }
}
void go(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])continue;
        for(int j=0;j<(int)e[i].size();j++)
            if(vis[e[i][j].first])deg[e[i][j].first]++;
    }
    memset(dp,INF,sizeof(dp));
    queue<int>q;
    q.push(n);
    dp[n][1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].first;
            if(!vis[v])continue;
            for(int j=1;j<=n;j++)
                dp[v][j]=min(dp[v][j],dp[u][j-1]+e[u][i].second);
            if(--deg[v]==0)q.push(v);
        }
    }
}
void get(int n,int t)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(dp[1][i]<=t)cnt=i;
    printf("%d\n",cnt);
    int u=1;
    while(u!=n)
    {
        printf("%d ",u);
        for(int i=0;i<(int)re[u].size();i++)
        {
            int v=re[u][i].first;
            if(dp[u][cnt]==dp[v][cnt-1]+re[u][i].second)
            {
                u=v;
                cnt--;
                break;
            }
        }
    }
    printf("%d\n",u);
}
int main()
{
    int n,m,T;
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=m;i++)
    {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        e[v].push_back(make_pair(u,t));
        re[u].push_back(make_pair(v,t));
    }
    pre(n);
    go(n);
    get(n,T);
    return 0;
}