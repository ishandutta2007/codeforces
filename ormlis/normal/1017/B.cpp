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
const int maxN = 100;
const int LG = 20;

void solve() {
    int n; cin >> n;
    str a, b; cin >> a >> b;
    vvi cnt(2, vi(2));
    rep(i, n) {
        cnt[a[i] - '0'][b[i] - '0']++;
    }
    ll ans = 0;
    rep(b1, 2) {
        rep(b2, 2) {
            rep(b3, 2) {
                rep(b4, 2) {
                    if (make_pair(b1, b2) < make_pair(b3, b4)) continue;
                    ll cur = 1ll * cnt[b1][b2] * cnt[b3][b4];
                    int t = 0;
                    if ((b1 | b2) == (b3 | b2)) t++;
                    if ((b3 | b4) == (b1 | b4)) t++;
                    if (t == 2) continue;
                    ans += cur;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}