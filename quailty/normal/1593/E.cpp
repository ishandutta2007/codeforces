#include<bits/stdc++.h>
using namespace std;
const int MAXN=400005;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
int deg[MAXN],dis[MAXN];
void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        deg[i]=e[i].size(),dis[i]=INF;
    queue<int> que;
    for(int i=1;i<=n;i++)
        if(e[i].size()<=1)
            que.push(i),dis[i]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(auto v:e[u])
            if(--deg[v]<=1 && dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                que.push(v);
            }
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res+=(dis[i]>k);
    printf("%d\n",res);
    for(int i=1;i<=n;i++)
        e[i].clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}