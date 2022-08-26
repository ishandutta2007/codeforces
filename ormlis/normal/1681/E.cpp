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
#define range(i, n) rep(i, n)
#define int long long

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

const int INFi = 2e18;
const ll INF = 2e18;
const int maxN = 1e5 + 30;
const int LG = 20;

int d[maxN][2][2];
int xf[2] = {1, 0};
int yf[2] = {0, 1};
int up[maxN][LG][2][2];

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    int n;
    cin >> n;
    rep(i, n - 1) {
        rep(j, 2) {
            rep(e, 2) {
                cin >> d[i][j][e];
                d[i][j][e]--;
            }
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        rep(f, 2) {
            rep(s, 2) {
                int cur = dist(d[i][f][0] + xf[f], d[i][f][1] + yf[f], d[i + 1][s][0],
                               d[i + 1][s][1]);
                cur = min(cur, dist(d[i][f][0], d[i][f][1], d[i][f ^ 1][0], d[i][f ^ 1][1]) +
                               dist(d[i][f ^ 1][0] + xf[f ^ 1], d[i][f ^ 1][1] + yf[f ^ 1],
                                    d[i + 1][s][0],
                                    d[i + 1][s][1]));
                up[i][0][f][s] = cur;
            }
        }
        for (int j = 1; j < LG; ++j) {
            if ((1 << j) + i >= n) break;
            rep(f, 2) {
                rep(s, 2) {
                    up[i][j][f][s] = INFi;
                    rep(mid, 2) {
                        up[i][j][f][s] = min(up[i][j][f][s],
                                             up[i][j - 1][f][mid] +
                                             up[i + (1 << (j - 1))][j - 1][mid][s]);
                    }
                }
            }
        }
    }
    int m;
    cin >> m;
    rep(_, m) {
        int x1, y1;
        int x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int A = max(x1, y1);
        int B = max(x2, y2);
        if (A > B) {
            swap(x1, x2);
            swap(y1, y2);
            swap(A, B);
        }
        if (A == B) {
            cout << dist(x1, y1, x2, y2) << '\n';
            continue;
        }
        int add = B - A;
        int ans = INFi;
        vi dp(2);
        rep(j, 2) dp[j] = dist(d[A][j][0], d[A][j][1], x1, y1);
        for (int j = LG - 1; j >= 0; --j) {
            if (A + (1 << j) >= B) continue;
            vi dp2(2, INFi);
            rep(x, 2) {
                rep(y, 2) {
                    dp2[y] = min(dp2[y], dp[x] + up[A][j][x][y]);
                }
            }
            dp = dp2;
            A += (1 << j);
        }
        rep(j, 2) ans = min(ans, dp[j] + dist(d[A][j][0] + xf[j], d[A][j][1] + yf[j], x2, y2));
        cout << ans + add << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}