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

const int N=500007;

int a[N];

int fac[N];
int inv[N];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(min(k,n)<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
int ans=mod-1;

bool good(int i,int j)
{
    if(i>0&&j>0&&j<=a[i]) return 1;
    return 0;
}

int add(int i,int j)
{
    if(good(i-1,j)) ans=(ans+npok(i+j-3,j-1))%mod;
    if(good(i,j-1)) ans=(ans+npok(i+j-3,j-2))%mod;
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
        int n;
        cin>>n;
        fac[0]=1;
        for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
        inv[N-1]=pot(fac[N-1],mod-2);
        for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=1;i<=n+1;i++) cin>>a[i];
        a[0]=a[1];
        for(int i=1;i<=n+2;i++)
        {
            if(a[i]==a[i-1]) add(i,a[i]+1);
            for(int j=a[i]+1;j<=a[i-1];j++) add(i,j);
        }
        if(a[1]==0) cout<<0;
        else cout<<ans;
    }

    return 0;
}