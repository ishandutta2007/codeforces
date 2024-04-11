#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15;
const ll mod = 998244353;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll binpow(ll a, ll b) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}

void run() {
    ll n, m; cin >> n >> m;
    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res += binpow(m % mod, i);

    for (int N = 1; N <= min(100ll, n); ++N) {
        ll num = 1;
        ll r2 = 1;
        for (int i = 1; i <= N; ++i) {
            if (gcd(num, i) == 1) num *= i;

            if (num > m) break;
            r2 = r2 * ((m / num) % mod) % mod;
        }
        if (num <= m) res -= r2;
    }
    cout << (res % mod + mod) % mod << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}