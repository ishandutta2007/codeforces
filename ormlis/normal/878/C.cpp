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
const int maxN = 1e3 + 5;
const int LG = 19;

struct dsu {
    vector<int> dsu;
    vi rnk;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)dsu[i] = i;
        rnk.resize(n, 1);
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (a == b) return false;
        if (rnk[a] > rnk[b]) swap(a, b);
        dsu[a] = b;
        rnk[b] += rnk[a];
        return true;
    }
};


void solve() {
    int n, k;
    cin >> n >> k;
    vvi s(n, vi(k));
    rep(i, n) rep(j, k) cin >> s[i][j];
    vi ind(n);
    vi ord(n);
    {
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) { return s[i][0] < s[j][0]; });
        rep(i, n) ind[ord[i]] = i;
    }
    vector<vector<int>> mx(n, vector<int> (k));
    vector<vector<int>> mn(n, vector<int> (k));
    rep(i, n) mx[i] = mn[i] = s[ord[i]];
    dsu d;
    d.build(n);
    set<int> have;
    for (int i = 0; i < n; ++i) {
        int cur = ind[i];
        while(true) {
            auto it = have.lower_bound(cur);
            if (it == have.end()) break;
            int nxt = *it;
            bool ok = false;
            rep(sp, k) if (mx[cur][sp] > mn[nxt][sp]) ok = true;
            if (!ok) break;
            have.erase(it);
            d.unio(cur, nxt);
            rep(sp, k) {
                mn[cur][sp] = min(mn[cur][sp], mn[nxt][sp]);
                mx[cur][sp] = max(mx[cur][sp], mx[nxt][sp]);
            }
        }
        while(true) {
            auto it = have.lower_bound(cur);
            if (it == have.begin()) break;
            it--;
            int nxt = *it;
            bool ok = false;
            rep(sp, k) if (mn[cur][sp] < mx[nxt][sp]) ok = true;
            if (!ok) break;
            have.erase(it);
            d.unio(cur, nxt);
            rep(sp, k) {
                mn[cur][sp] = min(mn[cur][sp], mn[nxt][sp]);
                mx[cur][sp] = max(mx[cur][sp], mx[nxt][sp]);
            }
        }
        have.insert(cur);
        cout << d.rnk[d.get_dsu(*have.rbegin())] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}