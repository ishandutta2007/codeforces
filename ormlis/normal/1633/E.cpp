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
        rnk.resize(n, 1);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (a == b) return false;
        if (rnk[a] > rnk[b]) swap(a, b);
        rnk[b] += rnk[a];
        dsu[a] = b;
        return true;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar<int, 3>> edges(m);
    rep(i, m) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }
    int k;
    vi q;
    {
        int p, a, b, c;
        cin >> p >> k >> a >> b >> c;
        q.resize(k);
        rep(i, p) cin >> q[i];
        for (int i = p; i < k; ++i) {
            q[i] = (1ll * q[i - 1] * a + b) % c;
        }
    }
    vector<int> good = {0};
    rep(i, m) {
        good.push_back(edges[i][0]);
        rep(j, i) {
            good.push_back((edges[i][0] + edges[j][0] + 2) / 2);
        }
    }
    sort(all(good));
    good.resize(unique(all(good)) - good.begin());
    vector<ll> coefs;
    vector<ll> adds;
    for (auto x : good) {
        vi ord(m);
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) {
            return abs(edges[i][0] - x) < abs(edges[j][0] - x);
        });
        ll coef = 0;
        ll add = 0;
        dsu d;
        d.build(n + 1);
        for (auto &i : ord) {
            auto[w, u, v] = edges[i];
            if (d.unio(u, v)) {
                if (x >= w) {
                    coef++;
                    add -= w;
                } else {
                    coef--;
                    add += w;
                }
            }
        }
        coefs.push_back(coef);
        adds.push_back(add);
    }
    ll ans = 0;
    rep(i, k) {
        int j = upper_bound(all(good), q[i]) - good.begin();
        j--;
        ll value = 1ll * coefs[j] * q[i] + adds[j];
        assert(value >= 0);
        ans ^= value;
    }
    cout << ans << '\n';
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