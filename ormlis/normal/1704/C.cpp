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

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 1e5 + 20;

void solve() {
    int n, m; cin >> n >> m;
    vi a(m);
    rep(i, m) cin >> a[i];
    sort(all(a));
    vi lens;
    rep(i, m) {
        int x = a[i] - 1;
        int y = a[(i + 1) % m] - 1;
        int r = (y - x + n - 1) % n;
        if (r == 0) continue;
        lens.push_back(r);
    }
    sort(rall(lens));
    int ans = 0;
    int us = 0;
    rep(i, (int)lens.size()) {
        int len = lens[i];
        len -= us * 2;
        if (len <= 0) continue;
        ans++;
        us++;
        len -= 2;
        if (len <= 0) continue;
        ans += len;
        us++;
    }
    cout << n - ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
     cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}