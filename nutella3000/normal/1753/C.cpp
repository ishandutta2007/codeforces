#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int mod = 998244353;

ll binpow(ll a, ll b) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}

ll inv(ll a) {
    return binpow(a, mod - 2);
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (auto& i : a) {
        cin >> i;
        cnt += i == 0;
    }
    int c = 0;
    for (int i = 0; i < cnt; ++i)
        c += a[i];

    ll res = (ll) n * (n-1) / 2 % mod;
    ll q = 0;
    for (ll i = 1; i <= c; ++i) {
        q += inv(i * i % mod);
    }
    cout << q % mod * res % mod << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}