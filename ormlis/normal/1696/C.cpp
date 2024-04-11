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
const int maxN = 5e5 + 20;
const int LG = 30;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi ca(n, 1);
    rep(i, n) cin >> a[i];
    int k;
    cin >> k;
    vi b(k), cb(k, 1);
    rep(i, k) cin >> b[i];
    rep(i, n) {
        while (a[i] % m == 0) {
            a[i] /= m;
            ca[i] *= m;
        }
    }
    rep(i, k) {
        while (b[i] % m == 0) {
            b[i] /= m;
            cb[i] *= m;
        }
    }
    int i = 0;
    int j = 0;
    while (i < n && j < k) {
        if (a[i] != b[j]) {
            cout << "NO\n";
            return;
        }
        int x = min(cb[j], ca[i]);
        cb[j] -= x;
        ca[i] -= x;
        while (i < n && ca[i] == 0) i++;
        while (j < k && cb[j] == 0) j++;
    }
    if (i != n || j != k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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