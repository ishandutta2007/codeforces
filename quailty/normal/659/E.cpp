#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
vector<int>e[MAXN];
bool vis[MAXN];
int bfs(int st)
{
    queue<pair<int,int> >q;
    q.push(make_pair(st,0));
    vis[st]=1;
    int acyc=1;
    while(!q.empty())
    {
        int u=q.front().first;
        int la=q.front().second;
        q.pop();
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i];
            if(v==la)continue;
            if(vis[v])acyc=0;
            else vis[v]=1,q.push(make_pair(v,u));
        }
    }
    return acyc;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int res=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])res+=bfs(i);
    printf("%d\n",res);
    return 0;
}