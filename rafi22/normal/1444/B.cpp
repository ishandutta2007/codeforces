#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

//Szybkie potegowanie
ll pot(ll x,ll p) {ll res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
struct dwumian
{
    vector<ll>silnia;
    dwumian(int n)
    {
        silnia.pb(1);
        for(ll i=1;i<=n;i++) silnia.pb(silnia.back()*i%mod);
    }
    ll npok(int n,int k) { return (silnia[n]*pot(silnia[k]*silnia[n-k]%mod,mod-2))%mod;}
    ll sil(int n) {return silnia[n];}
};

ll a[300007];

int main()
{
    mod=998244353;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+1+2*n);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=a[i+n]-a[i];
    ans%=mod;
    dwumian D(2*n);
    ans=ans*D.npok(2*n,n)%mod;
    cout<<ans;
    return 0;
}