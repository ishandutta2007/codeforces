#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
ll sum(ll l ,ll r){
    if (l >= r) return 0;
    ll ans = ((r%mod)*((r+1)%mod)/2)%mod;
    ans -= ((l%mod)*((l+1)%mod)/2)%mod;
    ans += mod;
    ans %= mod;
    return ans;
}
int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = (n%mod)*(m%mod)%mod;
    ll s = sqrt(n);
    rep(i,1,s+1){
        if (i > m) break;
        ll val = i*(n/i);
        val %= mod;
        ans -= val;
        ans += mod;
        ans %= mod;
    }
    debug(ans);
    if (s*s == n) s--;
    rep(i,1,s+1){
        ll k = n/(i+1);
        if (k >= m) continue;
        ll sa = sum(max(k,s),min(m,n/i));
        ans -= (sa*i)%mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans;

}