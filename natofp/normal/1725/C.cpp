#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int nax = 3e5 + 5;
const int mod = 998244353;

ll pp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}

ll f[nax];
ll iw[nax];

void prep(){
    f[0] = iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = (f[i - 1] * i) % mod;
        iw[i] = pp(f[i], mod - 2);
    }
}

ll binom(ll n, ll k){
    if(k < 0 || n < 0 || k > n) return 0LL;
    ll ans = f[n];
    ans *= iw[k];
    ans %= mod;
    ans *= iw[n - k];
    ans %= mod;
    return ans;
}

int n, m;
ll a[nax];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll tot = 0;
    for(int i=1;i<=n;i++) tot += a[i];
    ll pirs = 0;
    set<ll> ex;
    ll cur = 0;
    for(int i=1;i<=n;i++){
        cur += a[i];
        ex.insert(cur);
    }
    ll pref = 0;
    for(int i=1;i<=n;i++){
        pref += a[i];
        if(ex.count(pref + tot / 2) && tot % 2 == 0){
            pirs++;
        }
    }

    ll ans = 0;
    for(int i=0;i<=min((ll)m, pirs);i++){
        ll ways = binom(pirs, i);
        ways *= f[m];
        ways %= mod;
        ways *= iw[m - i];
        ways %= mod;

        ll col_left = m - i;
        ll pirs_left = pirs - i;
        ll normal_left = n - pirs * 2;
        if(pirs_left && col_left < 2) continue;
        if(normal_left && col_left < 1) continue;

        ll comb = 1;
        if(col_left){
            if(pirs_left){
                ll ways_one = ((col_left) * (col_left - 1)) % mod;
                ll ways_all = pp(ways_one, pirs_left);
                ways_all %= mod;
                ways *= ways_all;
                ways %= mod;
            }
            if(normal_left){
                ways *= pp(col_left, normal_left);
                ways %= mod;
            }
        }
        ans += ways;
        ans %= mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}