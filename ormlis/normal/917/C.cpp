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
const int maxN = 5e4 + 5;
const int LG = 30;

vector<vector<ll>> multiply(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    int n = a.size();
    vector<vector<ll>> c(n, vector<ll>(n, INF));
    rep(i, n) {
        rep(j, n) {
            rep(p, n) {
                c[i][j] = min(c[i][j], a[i][p] + b[p][j]);
            }
        }
    }
    return c;
}

void solve() {
    int x, k, n, q;
    cin >> x >> k >> n >> q;
    vi c(k);
    rep(i, k) cin >> c[i];
    map<int, int> et;
    vector<int> inter;
    rep(_, q) {
        int p, w;
        cin >> p >> w;
        et[p - 1] = w;
        for (int i = p - 2 - k; i <= p + 2; ++i) {
            if (i < 0) continue;
            if (i > n - x) continue;
            inter.push_back(i);
        }
    }
    vector<int> ind(1 << k, -1);
    vector<int> masks;
    int N = 0;
    rep(mask, 1 << k) {
        if (__builtin_popcount(mask) != x) continue;
        ind[mask] = N++;
        masks.push_back(mask);
    }
    inter.push_back(0);
    inter.push_back(n - x);
    sort(all(inter));
    inter.resize(unique(all(inter)) - inter.begin());
    vector<vl> mat(N, vl(N, INF));
    rep(i, N) {
        int mask = masks[i];
        int mask2 = mask >> 1;
        if (mask & 1) {
            rep(j, k) {
                if (mask2 & (1 << j)) continue;
                mat[i][ind[mask2 | (1 << j)]] = min(mat[i][ind[mask2 | (1 << j)]], (ll) c[j]);
            }
        } else {
            mat[i][ind[mask2]] = 0;
        }
    }

    vector<vector<vl>> pw(LG, vector<vl>(N, vl(N, INF)));
    pw[0] = mat;
    for (int i = 1; i < LG; ++i) pw[i] = multiply(pw[i - 1], pw[i - 1]);


    vl dp(N, INF);
    dp[ind[(1 << x) - 1]] = 0;

    auto go = [&](int i) {
        vl dp2(N, INF);
        rep(a, N) {
            if (dp[a] >= INF) continue;
            int mask = masks[a];
            int mask2 = mask >> 1;
            if (mask & 1) {
                rep(j, k) {
                    if (mask2 & (1 << j)) continue;
                    ll value = dp[a] + c[j] + et[i + j];
                    dp2[ind[mask2 | (1 << j)]] = min(dp2[ind[mask2 | (1 << j)]], value);
                }
            } else {
                dp2[ind[mask2]] = min(dp2[ind[mask2]], dp[a]);
            }
        }
        swap(dp, dp2);
    };

    for (int j = 1; j < (int) inter.size(); ++j) {
        if (inter[j] != inter[j - 1] + 1) {
            int st = inter[j] - inter[j - 1];
            vector<vector<ll>> res;
            for (int s = 0; s < LG; ++s) {
                if ((1 << s) & st) {
                    if (res.empty()) res = pw[s];
                    else res = multiply(res, pw[s]);
                }
            }
            vl dp2(N, INF);
            rep(mask, N) {
                rep(mask2, N) {
                    dp2[mask2] = min(dp2[mask2], dp[mask] + res[mask][mask2]);
                }
            }
            swap(dp, dp2);
        } else {
            go(inter[j]);
        }
    }
    cout << dp[ind[(1 << x) - 1]] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}