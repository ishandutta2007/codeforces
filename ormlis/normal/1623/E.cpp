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
const int maxN = 605;
const int LG = 20;


const int md = 1e9 + 7;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> c(n);
    rep(i, n) cin >> c[i];
    vi l(n), r(n);
    rep(i, n) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    vi h(n);
    vi pos(n);
    vvi up(n, vi(LG, 0));
    vi tin(n);
    vi tout(n);
    int T = 0;
    vi ord;
    string s;
    function<void(int)> dfs = [&](int v) {

        tin[v] = T++;
        for (int i = 1; i < LG; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
        if (l[v] != -1) {
            h[l[v]] = h[v] + 1;
            up[l[v]][0] = v;
            dfs(l[v]);
        }
        pos[v] = ord.size();
        ord.push_back(v);
        s += c[v];
        if (r[v] != -1) {
            h[r[v]] = h[v] + 1;
            up[r[v]][0] = v;
            dfs(r[v]);
        }
        tout[v] = T;
    };

    auto check = [&](int v, int p) {
        return tin[p] <= tin[v] && tout[v] <= tout[p];
    };
    dfs(0);
    vector<bool> banned(n);
    function<void(int)> ban = [&](int v) {
        if (banned[v]) return;
        if (l[v] != -1) ban(l[v]);
        if (r[v] != -1) ban(r[v]);
        banned[v] = true;
    };
    vector<int> u(n);
    function<void(int)> use = [&](int v) {
        if (u[v]) return;
        u[v] = true;
        k--;
        use(up[v][0]);
    };
    auto need_use = [&](int v) {
        int r = 0;
        for (int k = LG - 1; k >= 0; --k) {
            int t = up[v][k];
            if (h[v] - h[t] != (1 << k)) continue;;
            if (u[t]) continue;
            r += (1 << k);
            v = t;
        }
        return r + 1;
    };
    vector<vector<int>> add(n);
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && s[j] == s[i]) j++;
        if (j == n || s[j] < s[i]) {
            for (int e = i; e < j; ++e) if (!u[ord[e]]) ban(ord[e]);
            continue;
        }
        vector<int> to;
        for (int e = i; e < j; ++e) {
            if (banned[ord[e]] || u[ord[e]]) continue;
            to.push_back(ord[e]);
            add[ord[e]].clear();
        }
        if (to.empty()) continue;
        sort(all(to), [&](const int &i, const int &j) {
            return tin[i] < tin[j];
        });
        vector<int> stk;
        set<pair<int, int>> can;
        for (auto &v : to) {
            while (!stk.empty() && !check(v, stk.back())) stk.pop_back();
            if (stk.empty()) {
                can.insert({need_use(v), v});
            } else {
                add[stk.back()].emplace_back(v);
            }
            stk.push_back(v);
        }
        while (!can.empty()) {
            auto[cnt, v] = *can.begin();
            can.erase(can.begin());
            if (cnt > k) break;
            use(v);
            for (auto &w : add[v]) {
                can.insert({h[w] - h[v], w});
            }
        }
    }
    assert(k >= 0);
    rep(i, n) {
        cout << s[i];
        if (u[ord[i]]) cout << s[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}