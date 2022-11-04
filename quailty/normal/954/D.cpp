#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
void bfs(int n,int st,int dis[])
{
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    queue<int> q;
    q.push(st);
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto &v:e[u])
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
    }

}
int pre[MAXN],suf[MAXN];
int main()
{
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs(n,s,pre);
    bfs(n,t,suf);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            res+=(pre[i]+1+suf[j]>=pre[t] && pre[j]+1+suf[i]>=pre[t]);
    printf("%d\n",res-m);
    return 0;
}