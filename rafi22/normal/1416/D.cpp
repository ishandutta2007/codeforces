#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

pair<int,int> seg[800007];
int dsu[200007];
vector<int>G[500007];
int pre[500007];
int post[500007];
pair<int,int>edge[300007];
bool is[300007];
int val[200007];
int n,m,q;

int Find(int v)
{
    if(v==dsu[v]) return v;
    return dsu[v]=Find(dsu[v]);
}
int it,c=0,pot=1;
void Union(int u,int v)
{
   u=Find(u),v=Find(v);
   it++;
   dsu[it]=it;
   dsu[u]=it;
   dsu[v]=it;
   G[it].pb(u);
   if(v!=u) G[it].pb(v);
}

void dfs(int v)
{
    if(sz(G[v])==0)
    {
        pre[v]=++c;
        post[v]=c;
    }
    else
    {
        pre[v]=inf;
        post[v]=0;
    }
    for(auto u:G[v])
    {
        dfs(u);
        pre[v]=min(pre[v],pre[u]);
        post[v]=max(post[v],post[u]);
    }
}
pair<int,int> que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return {0,0};
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}
void ins(int u)
{
    seg[u].st=0;
    while(u>1)
    {
        u/=2;
        seg[u]=max(seg[2*u],seg[2*u+1]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {

        cin>>n>>m>>q;
        it=n;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++) cin>>val[i];
        for(int i=1;i<=n;i++) dsu[i]=i;
        for(int i=1;i<=m;i++) cin>>edge[i].st>>edge[i].nd;
        vector<pair<int,int>>querry;
        for(int i=0;i<q;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==2) is[y]=1;
            querry.pb({x,y});
        }
        for(int i=1;i<=m;i++) if(!is[i]) Union(edge[i].st,edge[i].nd);
        reverse(querry.begin(),querry.end());
        vector<int>ans;
        for(auto x:querry)
        {
            if(x.st==2) Union(edge[x.nd].st,edge[x.nd].nd);
            else ans.pb(Find(x.nd));
        }
        for(int i=1;i<=it;i++) if(Find(i)==i) dfs(i);
        for(int i=1;i<=n;i++)
        {
            seg[pre[i]+pot-1].st=val[i];
            seg[i+pot-1].nd=i;
        }
        for(int i=pot-1;i>0;i--) seg[i]=max(seg[2*i],seg[2*i+1]);
        reverse(ans.begin(),ans.end());
        for(auto v:ans)
        {
            pair<int,int> p=que(1,pre[v],post[v],1,pot);
            cout<<p.st<<endl;
            ins(p.nd+pot-1);
        }


    }

    return 0;
}