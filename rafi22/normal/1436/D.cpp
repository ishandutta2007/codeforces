#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector <int > G[200007];
int val[200007];
int DP[200007];
int sum[200007];
int leafs[200007];
int s[200007];
int ans=0;

void dfs(int v)
{
    sum[v]+=val[v];
    if(G[v].size()==0)
    {
        leafs[v]=1;
    }
    for(auto u:G[v])
    {
        dfs(u);
        sum[v]+=sum[u];
        leafs[v]+=leafs[u];
    }

    ans=max(ans,sum[v]/leafs[v]+min((int)1,sum[v]%leafs[v]));
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
        int n,a;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            cin>>a;
            G[a].pb(i);
        }
        for(int i=1;i<=n;i++) cin>>val[i];
        dfs(1);
        cout<<ans;

    }

    return 0;
}