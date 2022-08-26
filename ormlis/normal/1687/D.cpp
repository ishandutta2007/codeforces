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
    vector<pair<ll, ll>> bad;
    int T = 3e6;
    vi t(n, 1);
    for (int x = 0; x <= T; ++x) {
        ll v1 = 1ll * x * x;
        ll v2 = 1ll * (x + 1) * (x + 1);
        ll L = (v1 + v2 + 1) / 2;
        ll R = v2 - 1;
        ll dist = R - L;
        int i = 0;
        while (i < n) {
            int j = i + t[i];
            while (j < n && a[j] - a[j - 1] <= dist) {
                t[i] += t[j];
                j += t[j];
            }
            ll l1 = a[i];
            ll r1 = a[j - 1];
            ll lt = max(0ll, L - r1);
            ll rt = max(-1ll, R - l1);
            if (lt <= rt) {
                bad.emplace_back(lt, rt);
            }
            i = j;
        }
    }
    sort(all(bad));
    ll cur = 0;
    for (auto &[l, r] : bad) {
        if (cur < l) {
            cout << cur << '\n';
            return;
        }
        cur = max(cur, r + 1);
    }
    cout << cur << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}