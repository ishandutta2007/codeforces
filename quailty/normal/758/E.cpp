#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<62)-1;
ll x[MAXN],y[MAXN],w[MAXN],p[MAXN];
struct Edge
{
    ll to,w,p,id;
    Edge(){}
    Edge(ll _to,ll _w,ll _p,ll _id):to(_to),w(_w),p(_p),id(_id){}
};
vector<Edge>e[MAXN];
void fail()
{
    printf("-1");
    exit(0);
}
ll ms[MAXN],mw[MAXN],mp[MAXN];
void dfs1(int u,int fa)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].to;
        if(v==fa)continue;
        dfs1(v,u);
        int id=e[u][i].id;
        mp[id]=ms[v];
        mw[id]=w[id]+(mp[id]-p[id]);
        if(mw[id]<=0)
        {
            mp[id]+=1-mw[id];
            mw[id]=1;
        }
        if(mp[id]>p[id])fail();
        ms[u]+=ms[v]+mw[id];
    }
}
ll dfs2(int u,int fa,ll rem)
{
    ll sum=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].to;
        if(v==fa)continue;
        int id=e[u][i].id;
        if(rem<=p[id]-mp[id])
        {
            mw[id]+=rem;
            mp[id]+=rem;
            sum+=rem;
            rem=0;
        }
        else
        {
            rem-=p[id]-mp[id];
            sum+=p[id]-mp[id];
            mw[id]+=p[id]-mp[id];
            mp[id]=p[id];
        }
        ll tmp=dfs2(v,u,min(rem,mp[id]-ms[v]));
        rem-=tmp;
        sum+=tmp;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%lld%lld%lld%lld",&x[i],&y[i],&w[i],&p[i]);
        e[x[i]].push_back(Edge(y[i],w[i],p[i],i));
        e[y[i]].push_back(Edge(x[i],w[i],p[i],i));
    }
    dfs1(1,0);
    dfs2(1,0,INF);
    printf("%d\n",n);
    for(int i=1;i<=n-1;i++)
        printf("%lld %lld %lld %lld\n",x[i],y[i],mw[i],mp[i]);
    return 0;
}