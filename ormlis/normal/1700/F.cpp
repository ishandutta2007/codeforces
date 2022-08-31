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
const int maxN = 1e6 + 20;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    vvi a(2, vi(n + 1));
    rep(i, 2) rep(j, n) cin >> a[i][j];
    rep(i, 2) rep(j, n) {
            int x;
            cin >> x;
            a[i][j] -= x;
        }
    ll ans = 0;
    rep(i, n) {
        rep(j, 2) {
            while (a[j][i] > 0 && a[j ^ 1][i] < 0) {
                ans++;
                a[j][i]--;
                a[j ^ 1][i]++;
            }
        }
        rep(j, 2) {
            a[j][i + 1] += a[j][i];
            ans += abs(a[j][i]);
        }
    }
    if (a[0][n] == 0 && a[1][n] == 0) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}