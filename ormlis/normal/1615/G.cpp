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
const int maxN = 605;
const int LG = 20;

// author: 1-gon
struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;

    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }

    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }

    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }

    vector<int> trace(int x) {
        vector<int> vx;
        while (true) {
            while (bl[x] != x) x = bl[x];
            if (!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }

    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while (!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for (int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for (int z : b[c]) {
            bl[z] = c;
            for (int i = 0; i < c; i++) {
                if (g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }

    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while (vx.size() >= 2) {
            int z = vx.back();
            vx.pop_back();
            if (z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin()
                                       : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) -
                                         b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while (i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }

    int solve() {
        for (int ans = 0;; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for (int i = 0; i < m; i++) bl[i] = i;
            for (int i = 0; i < n; i++) {
                if (mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while (!Q.empty() && !aug) {
                int x = Q.front();
                Q.pop();
                if (bl[x] != x) continue;
                for (int y = 0; y < c; y++) {
                    if (bl[y] == y && g[x][y] != -1) {
                        if (d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        } else if (d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if (vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            } else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for (int i = 0; i < (int) A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if (i + 2 < (int) A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if (!aug) return ans;
        }
    }
};


vector<int> g1[maxN];
bool used[maxN];
bool was[maxN];
int comp[maxN];
bool ok = false;
int ee = 0;
int vv = 0;

void dfs(int v, int p) {
    ee += (int) g1[v].size();
    vv++;
    was[v] = true;
    for (auto &u : g1[v]) {
        if (u == p) continue;
        if (was[u]) {
            ok = true;
            continue;
        }
        dfs(u, v);
    }
}

void dfs2(int v) {
    used[v] = true;
    for (auto &u : g1[v]) {
        if (used[u]) continue;
        dfs2(u);
    }
}

void dfs3(int v) {
    for (auto &u : g1[v]) {
        if (comp[u]) continue;
        comp[u] = comp[v];
        dfs3(u);
    }
}

vector<pair<int, int>> gg[maxN];
bool U[maxN];

void my_assert(bool x) {
    if (!x) exit(0);
}

void find_answ(vector<int> a) {
    int n = a.size();
    vector<ar<int, 4>> kek1;
    for (int i = 0, j = 0; i < n; i = j) {
        if (a[i] != 0) {
            j++;
            continue;
        }
        while (j < n && a[j] == 0) j++;
        int len = j - i;
        if (len % 2 == 0) continue;
        my_assert(i > 0 && j < n);
        if (a[i - 1] == a[j]) {
            a[i] = a[i - 1];
            continue;
        }
        gg[a[i - 1]].emplace_back(a[j], kek1.size());
        gg[a[j]].emplace_back(a[i - 1], kek1.size());
        kek1.push_back({a[i - 1], a[j], i, j - 1});
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1] && a[i] != 0) {
            U[a[i]] = true;
        }
    }
    queue<int> q;
    vi h(kek1.size(), 0);

    auto make = [&](int i, int c) {
        h[i] = 1;
        auto[x, y, l, r] = kek1[i];
        if (x == c) {
            a[l] = c;
        } else {
            my_assert(y == c);
            a[r] = c;
        }
    };

    function<void(int)> dfss = [&](int v) {
        for (auto &[u, i] : gg[v]) {
            if (U[u] || h[i]) continue;
            U[u] = true;
            make(i, u);
            dfss(u);
        }
    };
    for (int i = 1; i < maxN; ++i) {
        if (U[i]) {
            dfss(i);
            continue;
        }
    }
    function<void(int)> go = [&](int v) {
        for (auto &[u, i] : gg[v]) {
            if (U[u] || h[i]) continue;
            U[u] = true;
            make(i, u);
            go(u);
        }
    };
    vi deg(maxN, 0);
    for (int i = 1; i < maxN; ++i) {
        if (U[i]) continue;
        deg[i] = gg[i].size();
        if (gg[i].size() == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        vector<pair<int, int>> tt;
        for (auto &[u, i] : gg[v]) {
            if (U[u]) continue;
            tt.emplace_back(u, i);
        }
        my_assert(tt.size() <= 1);
        if (tt.empty()) continue;
        auto[u, i] = tt.back();
        U[v] = true;
        make(i, v);
        deg[u]--;
        if (deg[u] == 1) {
            q.push(u);
        }
    }
    for (int i = 1; i < maxN; ++i) {
        if (deg[i] == 0 || U[i]) continue;
        go(i);
    }
    int k = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0 && a[i - 1] == 0) {
            while (k < maxN && U[k]) k++;
            a[i] = a[i - 1] = k++;
            if (k < maxN) U[k] = true;
        } else if (a[i - 1] == 0) {
            a[i - 1] = 1;
        }
    }
    rep(i, n) cout << a[i] << ' ';
    cout << '\n';
}


void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int L, R;
    int g = 0;
    {
        int k = 0;
        while (k < n && a[k] == 0) k++;
        if (k == n) {
            for (int i = 1; i < n; i += 2) {
                a[i] = a[i - 1] = (i / 2) + 1;
            }
            a[n - 1] = a[n - 2];
            rep(i, n) cout << a[i] << ' ';
            return;
        }
        L = k;
        g += k / 2;
        if (k % 2) {
            used[a[k]] = true;
            a[k - 1] = a[k];
        }
    }
    {
        int k = n - 1;
        while (k >= 0 && a[k] == 0) k--;
        R = k;
        g += (n - 1 - k) / 2;
        if ((n - 1 - k) % 2) {
            used[a[k]] = true;
            a[k + 1] = a[k];
        }
    }
    for (int i = L + 1; i <= R; ++i) {
        if (a[i] == 0) continue;
        if (a[i] != a[i - 1]) continue;
        used[a[i]] = true;
    }
    vector<ar<int, 4>> kek;
    for (int i = L, j = L; i <= R; i = j) {
        j = i + 1;
        if (a[i] != 0) continue;
        while (j <= R && a[j] == 0) j++;
        int len = j - i;
        int t1 = a[i - 1];
        int t2 = a[j];
        if (len % 2) {
            g += len / 2;
            g1[t1].push_back(t2);
            g1[t2].push_back(t1);
            continue;
        }
        g += (len) / 2 - 1;
        kek.push_back({t1, t2, i, j - 1});
    }
    for (int i = 1; i < maxN; ++i) {
        if (was[i]) continue;
        ee = vv = 0;
        ok = false;
        dfs(i, -1);
        if ((vv - 1) * 2 != ee) {
            ok = true;
        }
        if (ok) {
            used[i] = true;
        }
    }
    for (int i = 1; i < maxN; ++i) {
        if (used[i]) {
            dfs2(i);
        }
    }
    int C = 0;
    int t = 0;
    for (int i = 1; i < maxN; ++i) {
        if (used[i]) continue;
        t++;
        if (comp[i]) continue;
        C++;
        t--;
        comp[i] = C;
        dfs3(i);
    }
    blossom B(C + 1);
    set<pair<int, int>> wasss;
    for (auto &[a, b, i, j] : kek) {
        if (used[a] || used[b] || comp[a] == comp[b]) {
            g++;
            continue;
        }
        pair<int, int> tmp = {comp[a], comp[b]};
        if (tmp.first > tmp.second) swap(tmp.first, tmp.second);
        if (wasss.count(tmp)) continue;
        wasss.insert(tmp);
        B.add_edge(comp[a], comp[b]);
    }
    B.solve();
    set<pair<int, int>> have;
    for (int i = 1; i <= C; ++i) {
        if (i < B.mate[i]) {
            have.insert({i, B.mate[i]});
        }
    }
    auto ans = a;
    for (auto &[a, b, i, j] : kek) {
        if (used[a] || used[b] || comp[a] == comp[b]) {
            continue;
        }
        pair<int, int> cur = {comp[a], comp[b]};
        if (cur.first > cur.second) swap(cur.first, cur.second);
        if (!have.count(cur)) {
            g++;
            continue;
        }
        have.erase(cur);
        ans[i] = ans[i - 1];
        ans[j] = ans[j + 1];
    }
    find_answ(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}