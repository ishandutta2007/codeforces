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
int c[MAXN];
bool bfs(int st)
{
    queue<int>q;
    q.push(st);
    c[st]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i];
            if(c[v]==c[u])return 0;
            if(!c[v])
            {
                c[v]=-c[u];
                q.push(v);
            }
        }
    }
    return 1;
}
vector<int>res[2];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!c[i])
        {
            if(!bfs(i))return 0*printf("-1\n");
        }
    for(int i=1;i<=n;i++)
    {
        if(c[i]>0)res[0].push_back(i);
        else res[1].push_back(i);
    }
    for(int _=0;_<2;_++)
    {
        printf("%d\n",(int)res[_].size());
        for(int i=0;i<(int)res[_].size();i++)
            printf("%d ",res[_][i]);
        printf("\n");
    }
    return 0;
}