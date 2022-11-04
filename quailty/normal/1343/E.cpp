#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int MAXM=200005;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
int dis[3][MAXN];
ll p[MAXM];
void bfs(int st,int n,int dis[])
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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,a,b,c;
        scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
        for(int i=1;i<=m;i++)
            scanf("%lld",&p[i]);
        sort(p+1,p+m+1);
        for(int i=2;i<=m;i++)
            p[i]+=p[i-1];
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bfs(a,n,dis[0]);
        bfs(b,n,dis[1]);
        bfs(c,n,dis[2]);
        ll res=(1LL<<60)-1;
        for(int i=1;i<=n;i++)
        {
            if(dis[0][i]+dis[1][i]+dis[2][i]>m)continue;
            res=min(res,p[dis[1][i]]+p[dis[0][i]+dis[1][i]+dis[2][i]]);
        }
        printf("%lld\n",res);
        for(int i=1;i<=n;i++)
            e[i].clear();
    }
    return 0;
}