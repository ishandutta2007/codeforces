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

vector<int>G[100007];
bool odd[100007];
bool even[100007];
int mx,mn;

void dfs(int v,int o)
{
    int l=0;
    if(sz(G[v])==1) even[v]=1;
    for(auto u:G[v])
    {
        if(u!=o)
        {
            if(sz(G[u])==1) l++;
            dfs(u,v);
            odd[v]|=even[u];
            even[v]|=odd[u];
        }
    }
    if(odd[v]&&even[v]) mn=3;
    mx-=max(0LL,l-1);
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
        mx=n-1;
        mn=1;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        int r;
        for(int i=1;i<=n;i++) if(sz(G[i])>1) r=i;
        dfs(r,-1);
        cout<<mn<<" "<<mx;
    }

    return 0;
}