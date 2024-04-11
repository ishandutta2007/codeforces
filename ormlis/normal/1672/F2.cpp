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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) {
        a[i]--;
        b[i]--;
    }
    vvi g(n);
    rep(i, n) g[a[i]].push_back(b[i]);
    int mx = 0;
    rep(i, n) if (g[i].size() > g[mx].size()) mx = i;
    vi us(n);
    int t = 1;
    function<void(int)> dfs = [&](int v) {
        if (v == mx || us[v]) return;
        us[v] = 1;
        for (auto &u : g[v]) {
            dfs(u);
        }
        us[v] = t++;
    };
    rep(i, n) dfs(i);
    rep(i, n) {
        if (i == mx) continue;
        for (auto &j : g[i]) {
            if (us[j] >= us[i]) {
                cout << "WA\n";
                return;
            }
        }
    }
    cout << "AC\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}