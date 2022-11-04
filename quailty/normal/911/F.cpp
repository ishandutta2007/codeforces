#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
vector<int> e[MAXN];
int dis[MAXN],key[MAXN];
void dfs(int u,int f)
{
    for(auto &v:e[u])
    {
        if(v==f)continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
}
vector<int> dia;
bool get(int u,int f,int tar)
{
    if(u==tar)return 1;
    for(auto &v:e[u])
    {
        if(v==f)continue;
        if(get(v,u,tar))
        {
            dia.push_back(v);
            return 1;
        }
    }
    return 0;
}
vector<pair<int,int> > opt;
void build(int u,int f,int chs,int add,ll &res)
{
    for(auto &v:e[u])
    {
        if(v==f || key[v])continue;
        res+=(dis[v]=dis[u]+1)+add;
        opt.push_back(make_pair(chs,v));
        build(v,u,chs,add,res);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,dis[1]=0);
    int u=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[u])u=i;
    dfs(u,dis[u]=0);
    int v=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[v])v=i;
    get(u,0,v);
    dia.push_back(u);
    int d=(int)dia.size();
    ll res=0;
    for(int i=0;i<d;i++)
    {
        key[dia[i]]=1,res+=i;
        if(i)opt.push_back(make_pair(dia[0],dia[i]));
    }
    for(int i=0;i<d;i++)
    {
        int rt=dia[i];
        if(i<d/2)build(rt,dis[rt]=0,dia[d-1],d-1-i,res);
        else build(rt,dis[rt]=0,dia[0],i,res);
    }
    printf("%lld\n",res);
    reverse(opt.begin(),opt.end());
    for(int i=0;i<(int)opt.size();i++)
        printf("%d %d %d\n",opt[i].first,opt[i].second,opt[i].second);
    return 0;
}