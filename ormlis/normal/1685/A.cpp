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
const int maxN = 2e5 + 20;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(all(a));
    int d = n / 2;
    deque<int> b;
    rep(i, d) {
        if (i % 2) b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    vpi c;
    for (int i = 0; i < d; ++i) c.push_back({max(b[i], b[(i + 1) % d]), i});
    sort(all(c));
    vi ans(n);
    for (int i = d; i < n; ++i) {
        ans[c[i - d].second * 2 + 1] = a[i];
        if (c[i - d].first < a[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i, d) ans[i * 2] = b[i];
    rep(i, n) cout << ans[i] << ' ';
    cout << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}