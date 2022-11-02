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

int fac[2000007],inv[2000007];
int p[2000007];

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
        int n,m,k;
        cin>>n>>m>>k;
        fac[0]=1;
        for(int i=1;i<=2*n;i++) fac[i]=fac[i-1]*i%mod;
        inv[2*n]=pot(fac[2*n],mod-2);
        for(int i=2*n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        p[2*n]=pot(pot(2,2*n),mod-2);
        for(int i=2*n-1;i>=0;i--) p[i]=p[i+1]*2%mod;
        if(n==m)
        {
            cout<<k*n%mod<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=min(n,m);i++)
        {
            ans=(ans+k*i%mod*npok(n-i-1,m-i)%mod*p[n-i])%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}