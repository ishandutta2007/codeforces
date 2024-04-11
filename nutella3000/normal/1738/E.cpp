#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;
const int mod = 998244353;

ll fa[N], ifa[N];

ll binpow(ll a, ll b) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}
ll inv(ll a) {
    return binpow(a, mod - 2);
}
ll C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return fa[n] * ifa[k] % mod * ifa[n-k] % mod;
}

void run() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> p(n+1), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i+1] = p[i] + a[i];
    }
    for (int i = n-1; i >= 0; --i)
        s[i] = (i+1 < n ? s[i+1] : 0) + a[i];

    ll res = 1;

    if (p[n] == 0) {
        for (int q = 0; q < n - 1; ++q) {
            res = res * 2 % mod;
        }
        cout << res << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i) {
        int id1 = lower_bound(all(s), p[i], [](auto u, auto v) { return u > v; }) - s.begin();
        if (id1 >= n || s[id1] != p[i])
            continue;

        int cnt2 = upper_bound(all(s), p[i], [](auto u, auto v) { return u > v; }) - s.begin() - id1;
        int cnt1 = upper_bound(all(p), p[i]) - p.begin() - i;

        //cout << cnt1 << " " << cnt2 << '\n';
        if (2 * p[i] > p[n]) {
            break;
        }
        if (2 * p[i] < p[n]) {
            ll cnt = 0;
            for (int k = 0; k <= min(cnt1, cnt2); ++k)
                cnt += C(cnt1, k) * C(cnt2, k) % mod;

            res = cnt % mod * res % mod;
        } else {
            for (int q = 0; q < cnt1; ++q) {
                res = res * 2 % mod;
            }
        }
        i += cnt1 - 1;
    }
    cout << res << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    fa[0] = 1;
    for (int i = 1; i < N; ++i)
        fa[i] = fa[i-1] * i % mod;

    ifa[N-1] = inv(fa[N-1]);

    for (int i = N-2; i >= 0; --i)
        ifa[i] = ifa[i+1] * (i+1) % mod;

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}