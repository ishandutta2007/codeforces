#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for(int i = (a); i < (b); ++i)
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

const int md = 998244353;

void solve() {
    int n;
    cin >> n;
    vi cur(n - 1);
    iota(all(cur), 2);
    queue<int> q;
    q.push(1);
    vi col(n + 1, -1);
    vvi g(n + 1);
    col[1] = 0;
    while (!cur.empty()) {
        if (q.empty()) {
            q.push(cur.back());
            col[cur.back()] = 0;
            cur.pop_back();
            if (cur.empty()) break;
        }
        int v = q.front();
        q.pop();
        auto ask = [&](int l, int r, bool need) {
            if (l + 1 == r && !need) return 0;
            vi vv;
            for (int i = l; i < r; ++i) vv.push_back(cur[i]);
            if (need) vv.pb(v);
            cout << "? " << vv.size() << '\n';
            each(x, vv) cout << x << ' ';
            cout << endl;
            int res;
            cin >> res;
            return res;
        };
        vector<bool> us(cur.size());
        function<int(int, int, int)> rec = [&](int l, int r, int c) {
            if (c == -1) c = ask(l, r, true) - ask(l, r, false);
            if (!c) return c;
            if (l + 1 == r) {
                us[l] = true;
                return c;
            }
            int mid = (l + r) / 2;
            int w = rec(l, mid, -1);
            rec(mid, r, c - w);
            return c;
        };
        rec(0, (int) cur.size(), -1);
        vi cur2;
        rep(i, sz(cur)) if (!us[i]) cur2.push_back(cur[i]);
        rep(i, sz(cur)) if (us[i]) {
                col[cur[i]] = col[v] ^ 1;
                g[cur[i]].push_back(v);
                g[v].push_back(cur[i]);
                q.push(cur[i]);
            }
        cur = cur2;
    }
    vec<deque<int>> a(2);
    rep1n(i, n) a[col[i]].push_back(i);
    rep(_, 2) {
        if (a[0].empty()) {
            swap(a[0], a[1]);
            continue;
        }
        auto ask = [&]() {
            if (sz(a[0]) <= 1) return 0;
            cout << "? " << a[0].size() << '\n';
            each(x, a[0]) cout << x << ' ';
            cout << endl;
            int t;
            cin >> t;
            return t;
        };
        if (ask() == 0) {
            swap(a[0], a[1]);
            continue;
        }
        while (true) {
            int v = a[0].back();
            a[0].pop_back();
            if (ask() == 0) {
                a[0].push_back(v);
                break;
            }
        }
        while (true) {
            int v = a[0].front();
            a[0].pop_front();
            if (ask() == 0) {
                a[0].push_front(v);
                break;
            }
        }
        vi path;
        function<bool(int, int, int)> dfs = [&](int v, int p, int f) {
            path.push_back(v);
            if (v ==f ) return true;
            each(u, g[v]) {
                if (u == p) continue;
                if (dfs(u, v, f)) return true;
            }
            path.pop_back();
            return false;
        };
        assert(dfs(a[0].front(), -1, a[0].back()));
        cout << "N " << path.size() << '\n';
        each(x, path) cout << x << ' ';
        cout << endl;
        return;
    }
    cout << "Y " << a[0].size() << '\n';
    each(x, a[0]) cout << x << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20-7) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}