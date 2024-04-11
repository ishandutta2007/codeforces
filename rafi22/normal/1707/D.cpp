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

const int N=2007;

int fac[N];
int inv[N];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(min(k,n)<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}


vector<int>G[N];
int DP[N][N],pref[N][N];

int P[N][N],S[N][N];
int n;

void dfs(int v,int o)
{
    vector<int>V;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        V.pb(u);
    }
    if(sz(V)==0)
    {
        for(int i=1;i<=n;i++) DP[v][i]=1;
    }
    for(int i=0;i<=n;i++)
    {
        P[0][i]=1;
        S[sz(V)][i]=1;
    }
    for(int i=0;i<sz(V);i++)
    {
        P[i+1][0]=0;
        for(int j=1;j<=n;j++) P[i+1][j]=(P[i][j]*pref[V[i]][j])%mod;
    }
    for(int i=sz(V)-1;i>=0;i--)
    {
        S[i][0]=0;
        for(int j=1;j<=n;j++) S[i][j]=(S[i+1][j]*pref[V[i]][j])%mod;
    }
    for(int i=0;i<sz(V);i++)
    {
        //p>=l
        int a=(sz(V)==1),b=(sz(V)==1),c=0;
        for(int j=1;j<=n;j++)
        {
            if(j!=1) b=(b+a)%mod;
            if(v!=1)
            {
                DP[v][j]=(DP[v][j]+b*DP[V[i]][j])%mod;
                DP[v][j]=(DP[v][j]+c)%mod;
            }
            else
            {
                DP[v][j]=(DP[v][j]+a*DP[V[i]][j])%mod;
            }
            int x=(P[i][j]-P[i][j-1]+mod)*S[i+1][j]%mod;
            c=(c+a*DP[V[i]][j])%mod;
            a=(a+x)%mod;
            b=(b+x)%mod;
        }
        a=0,b=0,c=0;
        for(int j=1;j<=n;j++)
        {
            if(v!=1) DP[v][j]=(DP[v][j]+c)%mod;
            int x=(S[i+1][j]-S[i+1][j-1]+mod)*P[i][j-1]%mod;
            a=(a+x)%mod;
            b=(b+a)%mod;
            c=(c+a*DP[V[i]][j])%mod;
            if(v!=1) DP[v][j]=(DP[v][j]+b*DP[V[i]][j])%mod;
            else DP[v][j]=(DP[v][j]+a*DP[V[i]][j])%mod;
        }
    }
    for(int i=1;i<=n;i++) pref[v][i]=(pref[v][i-1]+DP[v][i])%mod;
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
        cin>>n>>mod;
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
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<i;j++)
            {
                DP[1][i]=(DP[1][i]-DP[1][j]*npok(i-1,j-1)%mod+mod)%mod;
            }
            cout<<DP[1][i]<<" ";
        }
    }

    return 0;
}