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
const int maxN = 2e3 + 5;
const int LG = 20;

const int K = 500;

void solve() {
    int n; cin >> n;
    vvi a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    vvi b(n, vi(n, 0));
    vi di = {0, 0, 1, -1};
    vi dj = {1, -1, 0, 0};
    int cur = 0;
    auto Op = [&] (int i, int j) {
        rep(w, 4) {
            int i2 = i + di[w], j2 = j + dj[w];
            if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= n) continue;
            b[i2][j2] ^= 1;
        }
        cur ^= a[i][j];
    };
    for(int i = 1; i < n; ++i) {
        rep(j, n) {
            if (!b[i - 1][j]) Op(i, j);
        }
    }
    cout << cur << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}