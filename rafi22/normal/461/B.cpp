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

bool c[100007];
vector <int> G[100007];
int DP[100007][2];
int qp(int a,int b)
{
	int res=1;
	for(;b;b>>=1LL,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
void dfs(int v,int o)
{
    for(auto u:G[v])
    {
        if(u!=o) dfs(u,v);
    }
    int i0=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        i0=i0*DP[u][0]%mod;
    }
    if(G[v].size()==0)
    {
        DP[v][1]=1;
        DP[v][0]=1;
        return ;
    }
    if(c[v])
    {
        DP[v][1]=i0;
        DP[v][0]=i0;
    }
    else
    {
        DP[v][0]=i0;
        for(auto u:G[v])
        {
            if(u!=o) DP[v][0]+=i0*qp(DP[u][0],mod-2)%mod*DP[u][1]%mod;
            DP[v][0]%=mod;
        }
        for(auto u:G[v])
        {
            if(u!=o) DP[v][1]+=i0*qp(DP[u][0],mod-2)%mod*DP[u][1]%mod;
            DP[v][1]%=mod;
        }
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
        int n,a;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a;
            G[a].pb(i);
            G[i].pb(a);
        }
        for(int i=0;i<n;i++) cin>>c[i];
        dfs(0,-1);
        cout<<DP[0][1];
    }

    return 0;
}