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

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    int ans = 0;
    vector<int> degree(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        ans += w[i];
        degree[i] = -1;
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ++degree[a];
        ++degree[b];
    }
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&w] (int a, int b) {
        return w[a] > w[b];
    });
    int ptr = 0;
    for (int k = 1; k < n; ++k) {
        cout << ans << ' ';
        while (ptr < n && degree[order[ptr]] == 0) ++ptr;
        if (ptr < n) {
            ans += w[order[ptr]];
            --degree[order[ptr]];
        }
    }
    cout << '\n';
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