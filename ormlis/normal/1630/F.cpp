#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 5e4 + 5;
const int LG = 19;

vector<int> divs[maxN];
int ind[maxN];

void precalc() {
    for(int i = 1; i < maxN; ++i) {
        for(int j = i * 2; j < maxN; j += i) divs[j].push_back(i);
    }
    rep(i, maxN) ind[i] = -1;
}

// source: https://judge.yosupo.jp/submission/48977
struct Kuhn {
    int N, M;
    vector<vector<int>> E;
    vector<int> matchA, matchB;
    vector<bool> vis;
    vector<bool> visA, visB;
    Kuhn(int N, int M) : N(N), M(M), E(N), matchA(N, -1), matchB(M, -1), vis(N), visA(N), visB(M) {}
    void add_edge(int u, int v) {
        E[u].push_back(v);
    }
    bool augment(int u) {
        vis[u] = true;
        for (auto v : E[u]) {
            int w = matchB[v];
            if (w == -1 || (not vis[w] && augment(w))) {
                matchA[u] = v, matchB[v] = u;
                return true;
            }
        }
        return false;
    }
    int mx = 0;
    int maximum_matching() {
        while (true) {
            bool converged = true;
            fill(all(vis), false);
            for (int u = 0; u < N; ++u) {
                if (not vis[u] && matchA[u] == -1 && augment(u)) {
                    converged = false;
                    ++mx;
                }
            }
            if (converged) break;
        }
        return mx;
    }

    void dfs(int v) {
        visA[v] = true;
        for(auto &u : E[v]) {
            visB[u] = true;
            if (matchB[u] != -1 && !visA[matchB[u]]) dfs(matchB[u]);
        }
    }

    vector<int> check() {
        rep(i, N) {
            if (matchA[i] == -1) {
                dfs(i);
            }
        }
        vector<int> ans;
        rep(i, N) {
            if (visA[i] && !visB[i]) ans.push_back(i);
        }
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        ind[a[i]] = i;
    }
    Kuhn gg(n * 2, n * 2);
    rep(i, n) {
        gg.add_edge(i, i + n);
        for(auto &d : divs[a[i]]) {
            if (ind[d] != -1) {
                gg.add_edge(i, ind[d]);
                gg.add_edge(i + n, ind[d] + n);
            }
        }
    }
    gg.maximum_matching();
    auto answer = gg.check();
    cout << n - (int)answer.size() << '\n';
    rep(i, n) ind[a[i]] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    precalc();
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}