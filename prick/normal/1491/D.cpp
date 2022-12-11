//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

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

void yes() {
    cout << "YES\n";
}

void no() {
    cout << "NO\n";
}

void solve() {
    int S, T;
    cin >> S >> T;
    
    if (S > T) {
        no();
        return;
    }
    if (S == T) {
        yes();
        return;
    }
    
    vector<int> u, v;
    for (int i = 0; i <= 29; ++i) {
        if (S & (1 << i)) {
            u.push_back(i);
        }
        if (T & (1 << i)) {
            v.push_back(i);
        }
    }

    while (!u.empty() && !v.empty() && u.back() == v.back()) {
        u.pop_back();
        v.pop_back();
    }
    
    // assert(!v.empty());
    while (sz(u) > sz(v)) {
        u.pop_back();
    }
    if (sz(u) < sz(v)) {
        no();
        return;
    }
    for (int i = 0; i < sz(v); ++i) {
        if (u[i] > v[i]) {
            no();
            return;
        }
    }
    yes();
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