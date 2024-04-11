#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=200005;
vector<int>e[MAXN];
int dis[MAXN];
void bfs(int st)
{
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i];
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        e[i].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1)e[i].push_back(i-1);
        if(i<n)e[i].push_back(i+1);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
}