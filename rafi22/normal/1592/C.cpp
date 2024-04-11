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

int a[200007];
vector<int>G[200007];
int DP[200007];
int x,c;

bool dfs(int v,int o)
{
    for(auto u:G[v])
    {
        if(u==o) continue;
        if(!dfs(u,v)) DP[v]^=DP[u];
    }
    DP[v]^=a[v];
    c+=(DP[v]==x);
    return (DP[v]==x);
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
        int n,k,u,v;
        x=0,c=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            x^=a[i];
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        if(x==0) cout<<"YES"<<endl;
        else
        {
            dfs(1,0);
            if(DP[1]!=0&&DP[1]!=x) cout<<"NO"<<endl;
            if(DP[1]==0) c--;
            while(c>k) c-=2;
            if(c>1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            DP[i]=0;
        }
    }

    return 0;
}