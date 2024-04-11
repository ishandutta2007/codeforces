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

vector<pair<int, int>> ans;

void solveTwo(vector<int> a, vector<int> b) {
    for (int i = 0; i < sz(b); ++i) {
        ans.emplace_back(a[0], b[i]);
    }
    for (int i = 1; i < sz(a); ++i) {
        ans.emplace_back(a[i], b[0]);
    }
    ans.emplace_back(a[0], b[0]);
}

void solveOne(vector<int> a) {
    if (sz(a) == 2) {
        for (int i = 1; ; ++i) {
            if (i != a[0] && i != a[1]) {
                a.push_back(i);
                break;
            }
        }
        ans.emplace_back(a[0], a[2]);
        ans.emplace_back(a[2], a[1]);
        ans.emplace_back(a[2], a[0]);
        return;
    }
    
    for (int i = 1; i < sz(a) - 1; ++i) {
        ans.emplace_back(a[0], a[i]);
    }
    ans.emplace_back(a[1], a.back());
    ans.emplace_back(a[0], a.back());
    ans.emplace_back(a[0], a[1]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> cycles;
    vector<char> used(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (used[i] || a[i] == i) {
            continue;
        }
        vector<int> t;
        t.push_back(i);
        used[i] = true;
        for (int cur = a[i]; cur != i; cur = a[cur]) {
            used[cur] = true;
            t.push_back(cur);
        }
        cycles.push_back(t);
    }
    while (sz(cycles) >= 2) {
        auto a = cycles.back();
        cycles.pop_back();
        auto b = cycles.back();
        cycles.pop_back();
        
        solveTwo(a, b);
    }
    if (!cycles.empty()) {
        solveOne(cycles.back());
    }
    
    cout << sz(ans) << '\n';
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << '\n';
    }
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
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}