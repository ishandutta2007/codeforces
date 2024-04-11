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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = double;
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

const int maxN = 1e3 + 5;
vector<int> g[maxN];
int used[maxN];
int T = 1;
int ve = 0;

void dfs(int v) {
    used[v] = T;
    ve++;
    for (auto &u : g[v]) {
        if (used[u] == T) continue;
        dfs(u);
    }
}

void solve() {
    int n;
    cin >> n;
    int d;
    cin >> d;
    for(int j = 1; j <= d; ++j) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        vector<int> trs;
        T++;
        int h = j;
        for (int i = 1; i <= n; ++i) {
            if (used[i] == T) continue;
            ve = 0;
            dfs(i);
            trs.push_back(ve);
            h -= (ve - 1);
        }
        sort(rall(trs));
        int ans = 0;
        rep(i, min((int)trs.size(), h + 1)) ans += trs[i];
        ans--;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(_, t) {
        solve();
    }
    return 0;
}