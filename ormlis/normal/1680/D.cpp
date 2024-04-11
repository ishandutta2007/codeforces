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
const int maxN = (1 << 20) + 1;
const int LG = 30;

void solve() {
    int n, k;
    cin >> n >> k;
    vl a(n + 1);
    vl c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) c[i] = 1;
        if (i) {
            c[i] += c[i - 1];
            a[i] += a[i - 1];
        }
    }
    ll ans = -2;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ll L1 = a[i - 1] - c[i - 1] * k;
            ll R1 = a[i - 1] + c[i - 1] * k;
            ll L3 = (a[j - 1] - a[n]) - (c[n] - c[j - 1]) * k;
            ll R3 = (a[j - 1] - a[n]) + (c[n] - c[j - 1]) * k;
            ll L2 = (a[j - 1] - a[i - 1]) - (c[j - 1] - c[i - 1]) * k;
            ll R2 = (a[j - 1] - a[i - 1]) + (c[j - 1] - c[i - 1]) * k;
            assert(L1 <= R1);
            assert(L2 <= R2);
            assert(L3 <= R3);
            R3 = min(R3, R1 + R2);
            L3 = max(L3, L1 + L2);
            if (L3 > R3) continue;
            // -(L1 + L2)
            // -(R1 + R2)
            if (R3 >= 0) {
                ll to = max(R3 - R2, L1);
                if (to <= 0) {
                    ans = max(ans, R3 - to);
                }
            }
            if (L3 <= 0) {
                ll to = min(L3 - L2, R1);
                if (to >= 0) {
                    ans = max(ans, to - L3);
                }
            }
        }
    }
    cout << ans + 1 << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}