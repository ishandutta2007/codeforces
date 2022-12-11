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

const int mod = (int) 1e9 + 7;

vector<int> parent;
vector<int> rk;
vector<int> odd;

void init(int m) {
    parent.resize(m + 1);
    rk.resize(m + 1);
    odd.resize(m + 1);
    for (int i = 0; i <= m; ++i) {
        parent[i] = i;
        rk[i] = 1;
        odd[i] = 0;
    }
}

int findSet(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

bool unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) {
        return false;
    }
    if (odd[a] && odd[b]) {
        return false;
    }
    if (rk[a] < rk[b]) {
        swap(a, b);
    }
    rk[a] += rk[b];
    parent[b] = parent[a];
    odd[a] = odd[a] + odd[b];
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    init(m);
    vector<int> ans;
    for (int id = 1; id <= n; ++id) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            x = findSet(x);
            if (!odd[x]) {
                odd[x] = id;
            }
        } else {
            int a, b;
            cin >> a >> b;
            if (unite(a, b)) {
                ans.push_back(id);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (i == findSet(i) && odd[i]) {
            ans.push_back(odd[i]);
        }
    }
    sort(ans.begin(), ans.end());
    int cnt = 1;
    for (int i = 0; i < sz(ans); ++i) {
        cnt *= 2;
        if (cnt >= mod) cnt -= mod;
    }
    cout << cnt << ' ' << sz(ans) << '\n';
    for (auto x: ans) {
        cout << x << ' ';
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
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}