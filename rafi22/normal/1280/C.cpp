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

const bool multi=1;

vector<pair<int,int>>G[200007];
int s[200007];
bool is[200007];
int mn,mx,n;

void dfs(int v,int o)
{
    s[v]=1;
    is[v]=1;
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        dfs(u.st,v);
        if(is[u.st]) mn+=u.nd;
        mx+=min(s[u.st],n-s[u.st])*u.nd;
        s[v]+=s[u.st];
        is[v]^=is[u.st];
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
        int a,b,c;
        cin>>n;
        n*=2;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b>>c;
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        mn=0,mx=0;
        dfs(1,0);
        cout<<mn<<" "<<mx<<endl;
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}