#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
vector<int> e[MAXN];
int res[MAXN],ind[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        e[v].push_back(u),ind[u]++;
    }
    priority_queue<int> pq;
    for(int i=1;i<=n;i++)
        if(!ind[i])pq.push(i);
    int t=n;
    while(!pq.empty())
    {
        int u=pq.top();
        res[u]=t--;
        pq.pop();
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i];
            if((--ind[v])==0)pq.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}