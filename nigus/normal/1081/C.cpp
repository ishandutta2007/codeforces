#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;
const ll mod = 998244353;

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%mod;
    return (((h*h)%mod)*i)%mod;
}

ll fac(ll i){
    ll res = 1;
    for(int c1 = 1; c1 <= i; c1++){
        res *= c1;
        res %= mod;
    }
    return res;
}

ll bin(ll i, ll j){
    if(i < j)return 0;
    ll a = fac(i);
    ll b = fac(j);
    ll c = fac(i-j);
    b = upp(b,mod-2);
    c = upp(c,mod-2);
    return (((a*b)%mod)*c)%mod;
}

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n >> m >> k;

    if(m == 1){
        cout << (k == 0) << "\n";
        return 0;
    }
    ll ans = upp(m-1,k);
    ans *= m;
    ans %= mod;
    ans *= bin(n-1,k);
    ans %= mod;
    cout << ans << "\n";

    return 0;
}