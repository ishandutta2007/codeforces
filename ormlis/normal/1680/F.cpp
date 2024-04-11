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
const int maxN = 4e6 + 20;
const int LG = 30;

struct dsu {
    vi dsu;
    vi xx;
    vi rnk;
    vi events;

    void init(int n) {
        dsu.resize(n);
        iota(all(dsu), 0);
        xx.resize(n);
        rnk.resize(n, 1);
    }

    pair<int, int> get_dsu(int a) {
        if (dsu[a] == a) return {a, xx[a]};
        auto p = get_dsu(dsu[a]);
        p.second ^= xx[a];
        return p;
    }

    bool unio(int a, int b) {
        auto ra = get_dsu(a);
        auto rb = get_dsu(b);
        if (ra.first == rb.first) return ra.second != rb.second;
        int A = ra.first;
        int B = rb.first;
        if (rnk[A] > rnk[B]) {
            swap(A, B);
            swap(ra, rb);
        }
        dsu[A] = B;
        rnk[B] += rnk[A];
        ra.second ^= xx[B];
        if (ra.second == rb.second) xx[A] ^= 1;
        events.push_back(A);
        return true;
    }

    int get_version() {
        return (int) events.size();
    }

    void back_to(int ver) {
        while ((int) events.size() > ver) {
            int a = events.back();
            events.pop_back();
            rnk[dsu[a]] -= rnk[a];
            dsu[a] = a;
        }
    }
};

vector<int> T[maxN];
int ans[maxN];
pi edges[maxN];
int n;

void add(int v, int l, int r, int lq, int rq, int i) {
    if (lq >= r || rq <= l) return;
    if (lq <= l && r <= rq) {
        T[v].push_back(i);
        return;
    }
    add(v << 1, l, (l + r) >> 1, lq, rq, i);
    add(v << 1 | 1, (l + r) >> 1, r, lq, rq, i);
}

bool dfs(int v, int L, int R, dsu &d) {
    int ver = d.get_version();
    bool ok = true;
    for (auto &i : T[v]) {
        if (!d.unio(edges[i].first, edges[i].second)) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        d.back_to(ver);
        return false;
    }
    if (L + 1 == R) {
        int to = 1 ^int(d.get_dsu(edges[L].first).second);
        for (int i = 1; i <= n; ++i) {
            ans[i] = to ^ int(d.get_dsu(i).second);
        }
        return true;
    }
    if (dfs(v << 1, L, (L + R) >> 1, d)) return true;
    if (dfs(v << 1 | 1, (L + R) >> 1, R, d)) return true;
    d.back_to(ver);
    return false;
}

void solve() {
    int m;
    cin >> n >> m;
    dsu d;
    d.init(n + 1);
    rep(i, m) cin >> edges[i].first >> edges[i].second;
    rep(i, m) {
        add(1, 0, m, 0, i, i);
        add(1, 0, m, i + 1, m, i);
    }
    if (!dfs(1, 0, m, d)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) cout << ans[i];
        cout << "\n";
    }
    rep(i, n + 1) ans[i] = 0;
    rep(i, m * 4) T[i].clear();
}


signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}