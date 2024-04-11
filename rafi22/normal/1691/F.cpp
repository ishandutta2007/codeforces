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

const int N=200007;

int fac[N];
int inv[N];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(min(k,n)<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}

vector<int>G[N];
int DP[N];
int s[N];
int c0[N],c1[N];

int n,k,ans,tot;

void dfs(int v,int o)
{
    s[v]=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        s[v]+=s[u];
        DP[v]=(DP[v]-npok(s[u],k)+mod)%mod;
    }
    DP[v]=(DP[v]+npok(s[v],k))%mod;
    tot=(tot+DP[v]*s[v])%mod;
}
void dfs1(int v,int o)
{
   // cout<<v<<" "<<tot<<endl;
    ans=(ans+tot)%mod;
    for(auto u:G[v])
    {
        if(u==o) continue;
        tot=(tot-DP[v]*s[v]%mod+mod)%mod;
        tot=(tot-DP[u]*s[u]%mod+mod)%mod;
        DP[v]=(DP[v]-npok(s[v],k)+mod)%mod;
        DP[u]=(DP[u]-npok(s[u],k)+mod)%mod;
        DP[v]=(DP[v]+npok(s[u],k))%mod;
        s[v]-=s[u];
        s[u]+=s[v];
        DP[v]=(DP[v]+npok(s[v],k))%mod;
        DP[u]=(DP[u]+npok(s[u],k))%mod;
        DP[u]=(DP[u]-npok(s[v],k)+mod)%mod;
        tot=(tot+DP[v]*s[v]%mod+mod)%mod;
        tot=(tot+DP[u]*s[u]%mod+mod)%mod;
        //cout<<u<<" "<<tot<<endl;
        dfs1(u,v);
    }
    tot=(tot-DP[o]*s[o]%mod+mod)%mod;
    tot=(tot-DP[v]*s[v]%mod+mod)%mod;
    DP[o]=(DP[o]-npok(s[o],k)+mod)%mod;
    DP[v]=(DP[v]-npok(s[v],k)+mod)%mod;
    DP[v]=(DP[v]+npok(s[o],k))%mod;
    s[v]-=s[o];
    s[o]+=s[v];
    DP[o]=(DP[o]+npok(s[o],k))%mod;
    DP[v]=(DP[v]+npok(s[v],k))%mod;
    DP[o]=(DP[o]-npok(s[v],k)+mod)%mod;
    tot=(tot+DP[o]*s[o]%mod+mod)%mod;
    tot=(tot+DP[v]*s[v]%mod+mod)%mod;
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
        cin>>n>>k;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        inv[n]=pot(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,0);
        dfs1(1,0);
        cout<<ans;
    }

    return 0;
}