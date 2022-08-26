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
const int maxN = 3e5 + 5;
const int LG = 19;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    int k; cin >> k;
    rep(_, m - 1) {
        int y; cin >> y;
        k = __gcd(k, y);
    }
    ll ans0 = 0, ans1 = 0;
    rep(i, k) {
        int mn = INFi;
        int cnt = 0;
        ll res = 0;
        for(int j = i; j < n; j += k) {
            mn = min(mn, abs(a[j]));
            res += abs(a[j]);
            if (a[j] < 0) cnt++;
        }
        if (cnt % 2 == 1) {
            ans1 += res;
            ans0 += res - mn * 2;
        } else {
            ans0 += res;
            ans1 += res - mn * 2;
        }
    }
    cout << max(ans0, ans1) << '\n';
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