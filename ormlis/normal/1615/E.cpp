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
const int maxN = 3e5 + 100;
const int LG = 20;

vector<int> g[maxN];
vi res;
int dfs(int v, int p) {
    int to = -1;
    for(auto &u : g[v]) {
        if (u == p) continue;
        int d = dfs(u, v);
        if (to == -1) {
            to = d;
            continue;
        }
        if (d <= to) {
            res.push_back(d);
        } else {
            res.push_back(to);
            to = d;
        }
    }
    return max(to + 1, 1);
}

void solve() {
    int n, k; cin >> n >> k;
    rep(_, n - 1) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    res.push_back(dfs(1, -1));
    sort(rall(res));
    if (res.size() <= k) {
        int to = (int)res.size();
        int need = n / 2;
        while(to < k && to < need) to++;
        cout << 1ll * (n - to) * to << '\n';
        return;
    }
    int ost = 0;
    for(int i = k; i < (int)res.size(); ++i) {
        ost += res[i];
    }
    ll ans = INF;
    for(int i = 0; i <= ost; ++i) {
        ans = min(ans, 1ll * (n - k - i) * (k - i));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}