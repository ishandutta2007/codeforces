#include <bits/stdc++.h>

//#define int long long
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

const bool multi=1;

vector<int>G[300007],G1[300007];
int pre[300007],post[300007],c=1,ans;
void dfs1(int v)
{
    pre[v]=c++;
    for(auto u:G1[v]) dfs1(u);
    post[v]=c++;
}
set<pair<int,int>>S1,S2;

void dfs(int v)
{
    pair<int,int>p,p1;
    p=*S1.upper_bound({pre[v],post[v]});
    if(p.nd!=mod&&p.nd<post[v]) S2.insert({pre[v],post[v]});
    else
    {
        p=*(--S1.upper_bound({pre[v],post[v]}));
        if(p.nd!=0&&p.nd>post[v])
        {
            S1.erase(p);
            S2.insert(p);
        }
        S1.insert({pre[v],post[v]});
    }
    ans=max(ans,sz(S1));
    for(auto u:G[v]) dfs(u);
    if(S1.count({pre[v],post[v]}))
    {
        S1.erase({pre[v],post[v]});
        p=*(--S2.upper_bound({pre[v],post[v]}));
        if(p.nd!=0&&p.nd>post[v])
        {
            p1=*S1.upper_bound(p);
            if(p1.nd==mod||p1.nd>p.nd)
            {
                S2.erase(p);
                S1.insert(p);
            }
        }
    }
    else S2.erase({pre[v],post[v]});
}

signed main()
{
    S1.insert({0,0});
    S1.insert({mod,mod});
    S2.insert({0,0});
    S2.insert({mod,mod});
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,a;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            cin>>a;
            G[a].pb(i);
        }
        for(int i=2;i<=n;i++)
        {
            cin>>a;
            G1[a].pb(i);
        }
        dfs1(1);
        dfs(1);
        cout<<ans-2<<endl;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            G1[i].clear();
        }
        ans=0;
        c=1;
    }

    return 0;
}