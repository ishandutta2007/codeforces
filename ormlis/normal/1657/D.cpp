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
const int maxN = 1e6 + 30;
const int LG = 100;

ll mx[maxN];

void solve() {
    int n, C;
    cin >> n >> C;
    rep(i, n) {
        int c, d, h;
        cin >> c >> d >> h;
        mx[c] = max(mx[c], 1ll * d * h);
    }
    for (int i = C; i >= 1; --i) {
        if (mx[i] == 0) continue;
        for (int j = i * 2, t = 2; j <= C; t++, j += i) {
            mx[j] = max(mx[j], mx[i] * t);
        }
    }
    for (int i = 1; i <= C; ++i) mx[i] = max(mx[i], mx[i - 1]);
    int m;
    cin >> m;
    rep(_, m) {
        ll d, h;
        cin >> d >> h;
        ll val = 1ll * d * h;
        int i = upper_bound(mx, mx + C + 1, val) - mx;
        if (i == C + 1) {
            cout << "-1 ";
        } else {
            cout << i << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}