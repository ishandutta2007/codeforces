#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int MAXM=200005;
int u[MAXM],v[MAXM];
vector<pair<int,int> > e[MAXN];
int dis[MAXN];
void bfs(int n,int st)
{
    for(int i=1;i<=n;i++)
        dis[i]=MAXN;
    queue<int> q;
    q.push(st);
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto &t:e[u])
        {
            int v=t.first;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
vector<int> pre[MAXN];
vector<string> res;
char now[MAXM];
void dfs(int n,int u,int k)
{
    if((int)res.size()>=k)return;
    if(u>n)
    {
        res.push_back(now+1);
        return;
    }
    for(auto &t:pre[u])
    {
        now[t]='1';
        dfs(n,u+1,k);
        now[t]='0';
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        e[u[i]].push_back({v[i],i});
        e[v[i]].push_back({u[i],i});
    }
    bfs(n,1);
    for(int u=2;u<=n;u++)
    {
        for(auto &t:e[u])
        {
            int v=t.first;
            if(dis[v]+1==dis[u])
                pre[u].push_back(t.second);
        }
    }
    for(int i=1;i<=m;i++)
        now[i]='0';
    dfs(n,2,k);
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%s\n",res[i].c_str());
    return 0;
}