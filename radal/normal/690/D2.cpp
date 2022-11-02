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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+20,mod = 1e6+3,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
ll poww(ll n,int k){
    if (k == 1) return n;
    ll r = poww(n,k/2);
    ll ans;
    if (k%2 == 0) ans = (r*r)%mod;
    else ans = (n*r*r)%mod;
    return ans;
}
ll f[N];
int main(){
    int n,c;
    cin >> n >> c;
    f[0] = 1;
    f[1] = 1;
    rep(i,2,n+c+10){
        f[i] = i*f[i-1];
        f[i] %= mod;
    }
    ll ans = 0;
    rep(i,1,n+1){
        ans += (f[i+c-1]*poww(f[i],mod-2)*poww(f[c-1],mod-2))%mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}