#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=5005;
const int INF=0x3f3f3f3f;
vector<int>e[MAXN];
int c[MAXN],k[MAXN],p[MAXN];
int dis[MAXN],ord[MAXN];
void bfs(int st,int n)
{
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    queue<int>q;
    q.push(st);
    dis[st]=0;
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
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int w;
    scanf("%d",&w);
    for(int i=1;i<=w;i++)
        scanf("%d%d%d",&c[i],&k[i],&p[i]);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=w;i++)ord[i]=i;
        sort(ord+1,ord+w+1,[](int i,int j){return p[i]<p[j];});
    while(q--)
    {
        int g,r;
        ll a;
        scanf("%d%d%I64d",&g,&r,&a);
        bfs(g,n);

        int tl=0,tr=n;
        while(tl<tr)
        {
            int tm=(tl+tr)/2;
            int now=0;
            ll cost=0;
            for(int i=1;i<=w;i++)
            {
                if(dis[c[ord[i]]]>tm)continue;
                if(now+k[ord[i]]<r)
                {
                    cost+=1LL*p[ord[i]]*k[ord[i]];
                    now+=k[ord[i]];
                }
                else
                {
                    cost+=1LL*(r-now)*p[ord[i]];
                    now=r;
                    break;
                }
            }
            if(now==r && cost<=a)tr=tm;
            else tl=tm+1;
        }
        printf("%d\n",(tl<n ? tl : -1));
    }
    return 0;
}