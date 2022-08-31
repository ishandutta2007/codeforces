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
const int maxN = 2e5 + 20;
const int LG = 30;

vi g[maxN];
int mt[maxN];
int used[maxN];
int T = 1;

bool kuhn(int v) {
    if (used[v] == T) return false;
    used[v] = T;
    for (auto &u : g[v]) {
        if (mt[u] == -1 || kuhn(mt[u])) {
            mt[u] = v;
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi to(n);
    int d = m / 3 + 1;
    rep(i, n) {
        if (a[i] >= d) {
            to[i] = 1;
        } else {
            to[i] = 0;
        }
    }
    rep(i, n) mt[i] = -1;
    rep(i, n) {
        if (!to[i]) continue;
        rep(j, n) {
            if (to[j]) continue;
            // a[i] * 2 + a[j] , a[i] + a[j], a[i], a[j]
            if (a[i] % a[j] == 0 && a[i] * 2 + a[j] <= m) {
                g[i].push_back(j);
            }
        }
    }
    rep(i, n) {
        if (!to[i]) continue;
        T++;
        if (!kuhn(i)) {
            cout << "-1\n";
            return;
        }
    }
    vi u(n);
    vpi ans;
    rep(i, n) {
        if (!to[i]) continue;
        assert(mt[i] != -1);
        int j = mt[i];
        assert(!u[j] && !u[i]);
        u[i] = 1;
        u[j] = 1;
        ans.push_back({a[i] * 2 + a[j], a[i] + a[j]});
    }
    rep(i, n) {
        if (!u[i]) {
            assert(to[i] == 0);
            ans.push_back({a[i] * 2, a[i] * 3});
            assert(a[i] * 3 <= m);
        }
    }
    cout << ans.size() << '\n';
    for(auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}