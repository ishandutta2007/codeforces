#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
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

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    rep(i, n - 2 * k) ans += a[i];
    int l = n - 2 * k;
    int mx = 0;
    for(int i = l, j = l; i < n; i = j) {
        while(j < n && a[j] == a[i]) j++;
        mx = max(mx, j - i);
    }
    mx -= (2 * k - mx);
    if (mx > 0) {
        ans += mx / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}