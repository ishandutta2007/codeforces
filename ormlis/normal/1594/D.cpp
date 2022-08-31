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
const int md = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vpi> g(n);
    vi col(n, -1);
    rep(_, m) {
        int i, j;
        string c; cin >> i >> j >> c;
        i--;
        j--;
        if (c[0] == 'i') {
            g[i].emplace_back(j, 1);
            g[j].emplace_back(i, 1);
        } else {
            g[i].emplace_back(j, 0);
            g[j].emplace_back(i, 0);
        }
    }
    ar<int, 2> cur = {0, 0};
    bool ok = true;
    function<void(int)> dfs = [&] (int v) {
        cur[col[v]]++;
        for(auto &[u, t] : g[v]) {
            if (col[u] == -1) {
                col[u] = col[v] ^ t;
                dfs(u);
            }
            if (col[u] != (col[v] ^ t)) ok = false;
        }
    };
    int ans = 0;
    rep(i, n) {
        if (col[i] == -1) {
            col[i] = 0;
            dfs(i);
            ans += max(cur[0], cur[1]);
            cur[0] = 0;
            cur[1] = 0;
        }
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}