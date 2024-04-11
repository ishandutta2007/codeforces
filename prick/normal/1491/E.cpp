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

const int maxn = (int) 2e5 + 42;

struct Edge {
    int to;
    int eid;
};

void fail() {
    cout << "NO\n";
    exit(0);
}

bool deleted[maxn];
vector<int> fib;
vector<Edge> graph[maxn];

int dfs(int v, int p, int curFibId, int &need, int &needFibId) {
    int sz = 1;
    for (auto e: graph[v]) {
        if (deleted[e.eid] || e.to == p) {
            continue;
        }
        int cur = dfs(e.to, v, curFibId, need, needFibId);
        if (need == -1 && (cur == fib[curFibId - 1] || cur == fib[curFibId - 2])) {
            deleted[e.eid] = true;
            need = e.to;
            if (cur == fib[curFibId - 1]) {
                needFibId = curFibId - 1;
            } else {
                needFibId = curFibId - 2;
            }
        }
        sz += cur;
    }
    return sz;
}

void solve(int root, int fibId) {
    if (fibId <= 1) {
        return;
    }
    
    int need = -1;
    int needFibId = -1;
    dfs(root, -1, fibId, need, needFibId);
    if (need == -1) {
        fail();
    }
    int rootFibId = (needFibId + 1 == fibId) ? fibId - 2: fibId - 1;
    solve(root, rootFibId);
    solve(need, needFibId);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(Edge{v, i});
        graph[v].push_back(Edge{u, i});
    }
    
    fib.push_back(1);
    fib.push_back(1);
    while (fib.back() < n) {
        fib.push_back(fib[sz(fib) - 2] + fib[sz(fib) - 1]);
    }
    if (n != fib.back()) {
        fail();
    }
    
    solve(1, sz(fib) - 1);
    cout << "YES\n";
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