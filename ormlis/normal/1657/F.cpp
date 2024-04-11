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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 100;


// source : https://github.com/ShahjalalShohag/code-library/blob/master/Graph%20Theory/2%20SAT.cpp
/*
zero Indexed
we have vars variables
F=(x_0 XXX y_0) and (x_1 XXX y_1) and ... (x_{vars-1} XXX y_{vars-1})
here {x_i,y_i} are variables
and XXX belongs to {OR,XOR}
is there any assignment of variables such that F=true
*/
struct twosat {
    int n;  // total size combining +, -. must be even.
    vector<vector<int> > g, gt;
    vector<bool> vis, res;
    vector<int> comp;
    stack<int> ts;

    twosat(int vars = 0) {
        n = vars << 1;
        g.resize(n);
        gt.resize(n);
    }

    //zero indexed, be careful
    //if you want to force variable a to be true in OR or XOR combination
    //add addOR (a,1,a,1);
    //if you want to force variable a to be false in OR or XOR combination
    //add addOR (a,0,a,0);

    //(x_a or (not x_b))-> af=1,bf=0
    void addOR(int a, bool af, int b, bool bf) {
        a += a + (af ^ 1);
        b += b + (bf ^ 1);
        g[a ^ 1].push_back(b);  // !a => b
        g[b ^ 1].push_back(a);  // !b => a
        gt[b].push_back(a ^ 1);
        gt[a].push_back(b ^ 1);
    }

    //(!x_a xor !x_b)-> af=0, bf=0
    void addXOR(int a, bool af, int b, bool bf) {
        addOR(a, af, b, bf);
        addOR(a, !af, b, !bf);
    }

    //add this type of condition->
    //add(a,af,b,bf) means if a is af then b must need to be bf
    void add(int a, bool af, int b, bool bf) {
        a += a + (af ^ 1);
        b += b + (bf ^ 1);
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : g[u]) if (!vis[v]) dfs1(v);
        ts.push(u);
    }

    void dfs2(int u, int c) {
        comp[u] = c;
        for (int v : gt[u]) if (comp[v] == -1) dfs2(v, c);
    }

    bool ok() {
        vis.resize(n, false);
        for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i);
        int scc = 0;
        comp.resize(n, -1);
        while (!ts.empty()) {
            int u = ts.top();
            ts.pop();
            if (comp[u] == -1) dfs2(u, scc++);
        }
        res.resize(n / 2);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1]) return false;
            res[i / 2] = (comp[i] > comp[i + 1]);
        }
        return true;
    }
};

const int A = 26;
vi g[maxN];
int h[maxN];
int p[maxN];
int ind[maxN][A];
int to[maxN];
int cnt[maxN];

void dfs(int v) {
    for (auto &u : g[v]) {
        if (u == p[v]) continue;
        p[u] = v;
        h[u] = h[v] + 1;
        dfs(u);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    rep(_, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int R = q;
    vector<string> S(q);
    vvi P(q);
    rep(i, q) {
        string s;
        int x, y;
        cin >> x >> y >> s;
        S[i] = s;
        vi path, pathR;
        while (x != y) {
            if (h[x] > h[y]) {
                path.push_back(x);
                x = p[x];
            } else {
                pathR.push_back(y);
                y = p[y];
            }
        }
        reverse(all(pathR));
        path.push_back(x);
        for (auto &v : pathR) path.push_back(v);
        assert(path.size() == s.size());
        int m = path.size();
        P[i] = path;
        rep(j, m) {
            int v = path[j];
            int a = s[j] - 'a';
            int b = s[m - 1 - j] - 'a';
            cnt[v]++;
            ind[v][a]++;
            if (a != b) ind[v][b]++;
        }
    }
    vector<char> res(n + 1, 'a');
    vector<char> res2(n + 1, 'a');
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) continue;
        vi kek;
        rep(j, A) {
            if (ind[i][j] == cnt[i]) kek.push_back(j);
        }
        if (kek.empty()) {
            cout << "NO\n";
            return;
        }
        if (kek.size() == 1) {
            to[i] = kek[0];
            res[i] = char('a' + kek[0]);
        } else {
            assert(kek.size() == 2);
            to[i] = -R;
            res[i] = char('a' + kek[0]);
            res2[i] = char('a' + kek[1]);
            R++;
        }
    }
    twosat sat(R);
    rep(i, q) {
        int m = P[i].size();
        rep(j, m) {
            int v = P[i][j];
            int a = S[i][j] - 'a';
            int b = S[i][m - 1 - j] - 'a';
            if (a == b) continue;
            if (to[v] >= 0) {
                int c = to[v];
                if (c == a && c == b) continue;
                if (c == a) {
                    sat.addOR(i, 1, i, 1);
                } else {
                    assert(c == b);
                    sat.addOR(i, 0, i, 0);
                }
            } else {
                if ((res[v] - 'a') == a) {
                    sat.addOR(i, 1, -to[v], 0);
                    sat.addOR(i, 0, -to[v], 1);
                } else {
                    sat.addOR(i, 1, -to[v], 1);
                    sat.addOR(i, 0, -to[v], 0);
                }
            }
        }
    }
    if (!sat.ok()) {
        cout << "NO\n";
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if (to[i] >= 0) continue;
        int v = -to[i];
        if (!sat.res[v]) {
            swap(res[i], res2[i]);
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i) cout << res[i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}