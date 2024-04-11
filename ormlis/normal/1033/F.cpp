#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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
    int w, n, m;
    cin >> w >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vec<str> g(m);
    rep(i, m) cin >> g[i];
    vi pw3(w + 1);
    pw3[0] = 1;
    rep(i, w) pw3[i + 1] = pw3[i] * 3;
    vi cnt(pw3[w]);
    vi cnt2(1 << w);
    rep(i, n) cnt2[a[i]]++;
    rep(mask, 1 << w) {
        rep(mask2, 1 << w) {
            int mask3 = 0;
            rep(j, w) {
                int t = Bit(mask, j);
                int d = Bit(mask2, j);
                if (!d) continue;
                mask3 += (t + 1) * pw3[j];
            }
            cnt[mask3] += cnt2[mask];
        }
    }
    rep(i, m) {
        ll res = 0;
        reverse(all(g[i]));
        function<void(int, int, int, bool)> dfs = [&](int j, int mask1, int mask3, bool ok) {
            if (j == w) {
                res += cnt2[mask1] * cnt[mask3];
                return;
            }
            if (g[i][j] == 'A') {
                dfs(j + 1, mask1, mask3, ok);
                dfs(j + 1, mask1 | (1 << j), mask3 + pw3[j], false);
            } else if (g[i][j] == 'o') {
                dfs(j + 1, mask1, mask3 + pw3[j] * 2, false);
                dfs(j + 1, mask1 | (1 << j), mask3, ok);
            } else if (g[i][j] == 'X') {
                dfs(j + 1, mask1, mask3 + pw3[j], ok);
                dfs(j + 1, mask1 | (1 << j), mask3 + pw3[j] * 2, ok);
            } else if (g[i][j] == 'x') {
                dfs(j + 1, mask1, mask3 + pw3[j] * 2, false);
                dfs(j + 1, mask1 | (1 << j), mask3 + pw3[j], false);
            } else if (g[i][j] == 'a') {
                dfs(j + 1, mask1 | (1 << j), mask3 + pw3[j] * 2, ok);
            } else if (g[i][j] == 'O') {
                dfs(j + 1, mask1, mask3 + pw3[j], ok);
            }
        };
        dfs(0, 0, 0, true);
        cout << res << '\n';
    }
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