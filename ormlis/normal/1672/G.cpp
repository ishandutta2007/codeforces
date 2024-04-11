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
const int maxN = 5e3;
const int LG = 100;
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
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

vi g[maxN];
int a[maxN];
bool used[maxN];
vi cur;

void dfs(int v) {
    if (used[v]) return;
    cur.push_back(v);
    used[v] = true;
    for (auto &u : g[v]) {
        dfs(u);
    }
}

void solve() {
    int r, c;
    cin >> r >> c;
    vvi b(r, vi(c));
    int cnt = 0;
    int XB = 0;
    rep(i, r) {
        rep(j, c) {
            char x;
            cin >> x;
            if (x == '?') {
                b[i][j] = -1;
            } else {
                b[i][j] = x - '0';
                XB ^= b[i][j];
            }
        }
    }
    int ans = 0;
    rep(i, r) {
        rep(j, c) {
            if (b[i][j] == -1) {
                g[i].push_back(j + r);
                g[j + r].push_back(i);
                cnt++;
            }
        }
    }
    if ((r % 2) == 0 && (c % 2) == 0) {
        cout << binpow(2, cnt) << '\n';
        return;
    }
    int C = 0;
    vvi comps;
    rep(i, r + c) {
        if (used[i]) continue;
        dfs(i);
        C++;
        comps.push_back(cur);
        cur.clear();
    }
    int CT = (cnt - (r + c - C));
    assert(CT >= 0);
    rep(X, 2) {
        int kek = 0;
        rep(i, r) {
            int x = 0;
            rep(j, c) {
                if (b[i][j] != -1) x ^= b[i][j];
            }
            if ((c % 2) == 1) {
                a[i] = (X ^ x);
            }
        }
        rep(j, c) {
            int x = 0;
            rep(i, r) {
                if (b[i][j] != -1) x ^= b[i][j];
            }
            if ((r % 2) == 1) {
                a[j + r] = (X ^ x);
            }
        }
        int valc = 1;
        int valr = 1;
        if (c % 2 == 1) {
            rep(i, r) {
                if (g[i].empty() && a[i] != 0) {
                    valc = 0;
                } else if (!g[i].empty()) {
                    valc = mul(valc, binpow(2, (int) g[i].size() - 1));
                }
            }
        }
        if (r % 2 == 1) {
            for (int i = r; i < r + c; ++i) {
                if (g[i].empty() && a[i] != 0) {
                    valr = 0;
                } else if (!g[i].empty()) {
                    valr = mul(valr, binpow(2, (int) g[i].size() - 1));
                }
            }
        }
        if ((r % 2) == 1 && (c % 2) == 1) {
            bool ok = true;
            for (auto &comp : comps) {
                int need = 0;
                for (auto &i : comp) {
                    need ^= a[i];
                }
                if (need == 1) {
                    ok = false;
                }
            }
            if (!ok) continue;
            ans = add(ans, binpow(2, CT));
        } else if (c % 2 == 1) {
            ans = add(ans, valc);
        } else if (r % 2 == 1) {
            ans = add(ans, valr);
        } else {
            assert(0);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}