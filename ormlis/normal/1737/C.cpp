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
const int maxN = 2e5 + 10;
const int md = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<bool> a(4);
    int cnt = 0;
    vi xx;
    vi yy;
    rep(i, 3) {
        int x, y;
        cin >> x >> y;
        int mask = ((x + y) % 2) * 2;
        mask |= (x % 2);
        a[mask] = 1;
        if ((x == 1 || x == n) || (y == 1 || y == n)) cnt++;
        xx.push_back(x);
        yy.push_back(y);
    }
    sort(all(xx));
    sort(all(yy));
    int x, y;
    cin >> x >> y;
    int mask2 = ((x + y) % 2) * 2;
    mask2 |= (x % 2);
    if (a[mask2] == 0) {
        cout << "NO\n";
        return;
    }
    if (cnt == 3) {
        if (x != xx[1] && y != yy[1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}