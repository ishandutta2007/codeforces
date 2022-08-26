#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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
const int LG = 20;
const int maxN = 2e5 + 10;

vpi g[maxN];
ll dist[maxN];
int T = 0;
int z[maxN];
int k;
vector<int> passq[maxN], fineq[maxN];
vi qs[maxN];
ll ans[maxN];

ll dfs(int v, int p, vector<ar<ll, 3>> cur) {
    if (cur.back()[2] == z[v]) {
        cur.back()[1] = dist[v];
    } else {
        cur.push_back({dist[p], dist[v], z[v]});
    }
    ll mask = 0;
    for (auto[u, t] : g[v]) {
        if (u == p) continue;
        dist[u] = dist[v] + t;
        ll res = dfs(u, v, cur);
        if (z[u] == z[v]) mask |= res;
    }
    cur.pop_back();
    vector<pair<int, int>> events;
    events.emplace_back(0, 0);
    events.emplace_back(0, 0);
    vl res(k);
    for (auto[l, r, j] : cur) {
        ll ct = (r - l) / T;
        if ((r - l) % T) {
            int L = (l + 1) % T;
            int R = (r + 1) % T;
            assert(L != R);
            events.emplace_back(L, j);
            events.emplace_back(R, j);
            if (L > R) {
                events.emplace_back(0, j);
            }
        }
        res[j] = ct;
    }
    sort(all(events));
    vi tomask;
    int msk = 0;
    ll cv = dist[v] % T;
    for (int l = 0, r = 0; l < (int) events.size(); l = r) {
        while (r < (int) events.size() && events[r].first == events[l].first)
            msk ^= (1 << events[r++].second);
        if (events[l].first <= cv && (r == (int) events.size() || events[r].first > cv)) {
            mask |= (1ll << ((ll) tomask.size()));
        }
        tomask.push_back(msk);
    }
    for (auto i : qs[v]) {
        auto pass = passq[i];
        auto fine = fineq[i];
        ans[i] = INF;
        rep(j, (int) tomask.size()) {
            if (((1ll << ((ll) j)) & mask) == 0) continue;
            msk = tomask[j];
            ll result = 0;
            rep(e, k) {
                ll val = res[e];
                if (msk & (1 << e)) val++;
                if (val == 0) continue;
                if (pass[e] / val < fine[e]) {
                    result += pass[e];
                } else {
                    result += min(val * fine[e], 1ll * pass[e]);
                }
            }
            ans[i] = min(ans[i], result);
        }
    }
    return mask;
}

void solve() {
    int n;
    cin >> n;
    rep(_, n - 1) {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
    }
    cin >> k;
    rep(i, n) {
        char x;
        cin >> x;
        z[i + 1] = x - 'A';
    }
    vi pass(k), fine(k);
    rep(i, k) cin >> pass[i];
    rep(i, k) cin >> fine[i];
    cin >> T;
    int q;
    cin >> q;
    int qq = 0;
    rep(id, q) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            char x;
            int c;
            cin >> x >> c;
            pass[x - 'A'] = c;
        } else if (tp == 2) {
            char x;
            int c;
            cin >> x >> c;
            fine[x - 'A'] = c;
        } else {
            int v;
            cin >> v;
            if (v == 1) {
                ans[qq++] = 0;
            } else {
                passq[qq] = pass;
                fineq[qq] = fine;
                qs[v].push_back(qq++);
            }
        }
    }
    for (auto[u, t] : g[1]) {
        dist[u] = t;
        vector<ar<ll, 3>> cur;
        cur.push_back({0, 0, z[u]});
        dfs(u, 1, cur);
    }
    rep(i, qq) cout << ans[i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}