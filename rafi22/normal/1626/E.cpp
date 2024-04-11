#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=300007;

bool is[N];
bool is1[N];
vector<int>G[N];
set<int>S;
int d[N];
bool ans[N];

bool check(int v)
{
    if(is1[v]&&d[v]>1) S.insert(v);
    else S.erase(v);
}

void dfs(int v,int o)
{
    d[v]=is[v];
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        d[v]+=d[u];
    }
    check(v);
}
void dfs1(int v,int o)
{
    if(sz(S)>0) ans[v]=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        d[v]-=d[u];
        d[u]+=d[v];
        check(v);
        check(u);
        dfs1(u,v);
        d[u]-=d[v];
        d[v]+=d[u];
        check(v);
        check(u);
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>is[i];
            is1[i]=is[i];
        }
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!is[i]) continue;
            for(auto u:G[i]) is1[u]=1;
        }
        dfs(1,0);
        dfs1(1,0);
        for(int i=1;i<=n;i++) cout<<(is1[i]|ans[i])<<" ";
    }

    return 0;
}