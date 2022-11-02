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

int fac[5007];
int inv[5007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(min(k,n)<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
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
        mod=mod1;
        int n,k;
        cin>>n>>k;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        inv[n]=pot(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        vector<int>V;
        V.pb(0);
        string s;
        cin>>s;
        if(k==0)
        {
            cout<<1;
            return 0;
        }
        for(int i=0;i<n;i++) if(s[i]=='1') V.pb(i+1);
        V.pb(n+1);
        int ans=1;
        for(int i=k;i<sz(V)-1;i++)
        {
            ans=(ans+npok(V[i+1]-V[i-k]-1,k)-1)%mod;
            if(i>k) ans=(ans-(npok(V[i]-V[i-k]-1,k-1)-1)+mod)%mod;
        }
        cout<<ans;
    }

    return 0;
}