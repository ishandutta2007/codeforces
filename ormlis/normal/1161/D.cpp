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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
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

const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res,  a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[n - 1] == '1') {
        cout << "0\n";
        return;
    }
    int ans = 0;
    for (int bl = 1; bl < n; ++bl) {
        vector<int> col(n * 2, -1);
        col[0] = col[n - 1] = 1;
        rep(i, bl) col[i + n] = 0;
        vec<vec<pi>> g(n * 2);
        rep(i, n / 2) {
            int j = n - 1 - i;
            g[i].emplace_back(j, 0);
            g[j].emplace_back(i, 0);
        }
        col[n + bl] = col[n + n - 1] = 1;
        rep(i, (n - bl) / 2) {
            int j = (n - bl) - 1 - i;
            g[i + n + bl].emplace_back(j + n + bl, 0);
            g[j + n + bl].emplace_back(i + n + bl, 0);
        }
        rep(i, n) {
            if (s[i] == '?') continue;
            int t = s[i] - '0';
            g[i].emplace_back(i + n, t);
            g[i + n].emplace_back(i, t);
        }
        bool bad = false;
        vi used(n * 2);
        function<void(int)> dfs = [&](int v) {
            used[v] = 1;
            for (auto &[u, x] : g[v]) {
                if (col[u] == -1) {
                    col[u] = col[v] ^ x;
                    dfs(u);
                }
                if ((col[v] ^ x) != col[u]) bad = true;
            }
        };
        int t = 0;
        rep(i, n * 2) {
            if (used[i]) continue;
            if (col[i] != -1) {
                dfs(i);
                if (bad) break;
            }
        }
        if (bad) continue;
        rep(i, n * 2) {
            if (used[i]) continue;
            assert(col[i] == -1);
            col[i] = 0;
            dfs(i);
            t++;
            if (bad) break;
        }
        if (bad) continue;
        ans = add(ans, binpow(2, t));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}