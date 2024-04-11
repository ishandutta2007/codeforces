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

vector<int>G[300007];
int skok[300007][20];
int pre[300007];
int post[300007],c=1;
vector<pair<int,int>>vec[300007];
int pref[300007];
int cnt[300007];
int pref1[300007];
int cnt1[300007];
int cnt2[300007];

void dfs(int v,int o)
{
    pre[v]=c++;
    skok[v][0]=o;
    if(o==0) for(int i=0;i<20;i++) skok[v][i]=1;
    else for(int i=1;i<20;i++) skok[v][i]=skok[skok[v][i-1]][i-1];
    for(auto u:G[v]) if(u!=o) dfs(u,v);
    post[v]=c++;
}
bool child(int a,int b) {return (pre[b]>=pre[a]&&post[b]<=post[a]);}

pair<int,pair<int,int> > lca(int a,int b)
{
    if(a==b) return {a,{-1,-1}};
    if(child(b,a)) swap(a,b);
    int it=19,p=b;
    while(true)
    {
        bool x=0;
        for(; it>=0; it--)
        {
            if(!child(skok[p][it],a))
            {
                x=1;
                p=skok[p][it];
                break;
            }
        }
        if(!x) break;
    }
    if(a!=skok[p][0])
    {
        int p1=p;
        it=19,p=a;
        while(true)
        {
            bool x=0;
            for(; it>=0; it--)
            {
                if(!child(skok[p][it],b))
                {
                    x=1;
                    p=skok[p][it];
                    break;
                }
            }
            if(!x) break;
        }
        return {skok[p1][0],{p1,p}};
    }
    else return {skok[p][0],{p,-1}};
}
void dfs1(int v,int o)
{
    pref[v]=cnt[v]+pref[o];
    pref1[v]+=cnt1[v]+pref1[o];
    for(auto u:G[v]) if(u!=o) dfs1(u,v);
}
struct Q
{
    int lc,a,b,l,r;
};
Q z[300007];
map<pair<int,int>,int>ile;


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
        int n,m,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,0);
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            pair<int,pair<int,int>>xd=lca(a,b);
            z[i]={xd.st,a,b,xd.nd.st,xd.nd.nd};
            cnt[z[i].lc]++;
            if(z[i].l!=-1) cnt1[z[i].l]++;
            if(z[i].r!=-1) cnt1[z[i].r]++;
        }
        dfs1(1,0);
        int ans=0;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=m;i++)
        {
            ans+=pref[z[i].a]+pref[z[i].b]-2*pref[z[i].lc]+cnt[z[i].lc];
            cnt[z[i].lc]++;
            ans-=pref1[z[i].a]+pref1[z[i].b]-2*pref1[z[i].lc];
            if(z[i].l!=-1) ans+=cnt1[z[i].l];
            if(z[i].r!=-1) ans+=cnt1[z[i].r];
            if(z[i].l!=-1) ans-=cnt2[z[i].l];
            if(z[i].r!=-1) ans-=cnt2[z[i].r];
            if(z[i].l!=-1) cnt2[z[i].l]++;
            if(z[i].r!=-1) cnt2[z[i].r]++;
        }
        for(int i=1;i<=m;i++)
        {
            if(z[i].l!=-1&&z[i].r!=-1)
            {
                ans+=ile[{min(z[i].l,z[i].r),max(z[i].l,z[i].r)}];
                ile[{min(z[i].l,z[i].r),max(z[i].l,z[i].r)}]++;
            }
        }
        cout<<ans<<endl;





    }

    return 0;
}