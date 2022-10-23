#include "bits/stdc++.h"

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

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 100 + 10;
const int md = 1e9 + 7;

int dp[2][maxN][maxN][2];

void precalc() {
    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 0;
    dp[1][0][0][0] = 0;
    dp[1][0][0][1] = 1;
    for(int x = 0; x < maxN; ++x) {
        for(int y = 0; y < maxN; ++y) {
            if (x == 0 && y == 0) continue;
            for(int cur = 0; cur < 2; ++cur) {
                for(int c = 0; c < 2; ++c) {
                    bool ok = true;
                    if (x) ok &= (dp[cur^1][x-1][y][c] == 1);
                    if (y) ok &= (dp[cur^1][x][y-1][c^(cur^1)] == 1);
                    dp[cur][x][y][c] = (!ok);
                }
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    int x =0, y = 0;
    rep(i, n) {
        int v; cin >> v;
        if (v % 2) y++;
        else x++;
    }
    cout << (dp[0][x][y][0] ? "Alice\n" : "Bob\n");
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    precalc();
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}