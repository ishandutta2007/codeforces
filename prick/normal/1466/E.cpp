//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}

const int maxbit = 60;
const int mod = (int) 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> cnt(maxbit);
    for (int i = 0; i < n; ++i) {
        for (int bit = 0; bit < maxbit; ++bit) {
            if (a[i] & (1LL << bit)) {
                ++cnt[bit];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int A = 0, B = 0;
        for (int bit = 0; bit < maxbit; ++bit) {
            int value = 1LL << bit;
            if (a[i] & value) {
                A += value % mod * cnt[bit];
                A %= mod;
                B += value % mod * n;
                B %= mod;
            } else {
                B += value % mod * cnt[bit];
                B %= mod;
            }
        }
        ans += A * B;
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}