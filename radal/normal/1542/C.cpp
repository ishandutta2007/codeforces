#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
ll fac[42];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    fac[0] = 1;
    rep(i,1,41){
        fac[i] = lcm(fac[i-1],i);
    }
    while (T--){
        ll n;
        cin >> n;
        ll ans = 0;
        rep(i,1,41){
            ll x;
            if (i < 40) x = n/fac[i]-n/fac[i+1];
            else  x = n/fac[i];
            x %= mod;
            ans += (x*(i+1))%mod;
            ans %= mod;
        }
        cout << ans << endl;

    }
    return 0;
}