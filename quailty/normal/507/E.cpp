#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
const int MAXM=100005;
const int INF=0x3f3f3f3f;
int x[MAXM],y[MAXM],z[MAXM],usd[MAXM];
pair<int,int> operator + (const pair<int,int> &a,const pair<int,int> &b)
{
    return make_pair(a.first+b.first,a.second+b.second);
}
vector<pair<int,int> >e[MAXN];
pair<int,int>dis[MAXN],pre[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        e[x[i]].push_back(make_pair(y[i],i));
        e[y[i]].push_back(make_pair(x[i],i));
    }
    for(int i=1;i<=n;i++)
        dis[i]=make_pair(INF,INF);
    queue<int>q;
    q.push(1);
    dis[1]=make_pair(0,0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].first,id=e[u][i].second;
            if(dis[v]>dis[u]+make_pair(1,z[id]^1))
            {
                dis[v]=dis[u]+make_pair(1,z[id]^1);
                pre[v]=make_pair(u,id);
                q.push(v);
            }
        }
    }
    int now=n;
    while(now!=1)
    {
        usd[pre[now].second]=1;
        now=pre[now].first;
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(usd[i]^z[i])cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=m;i++)
        if(usd[i]^z[i])printf("%d %d %d\n",x[i],y[i],z[i]^1);
    return 0;
}