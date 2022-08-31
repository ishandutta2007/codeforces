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

void solve() {
    int n, k;
    cin >> n >> k;
    vi cur(n);
    vector<pair<int, int>> events;
    rep(i, n) {
        int x;
        cin >> x;
        cur[i] = x;
        int val = x;
        // [x / t] == val
        // val * t <= x < (val + 1) * t
        // t <= x / val
        while (val > 0) {
            int t = x / val + 1;
            if (t > k) break;
            int val2 = x / t;
            assert(val2 < val);
            events.emplace_back(val, val2);
            val = val2;
        }
        events.emplace_back(val, -1);
    }
    sort(rall(events));
    int mn = *min_element(all(cur));
    int ans = *max_element(all(cur)) - mn;
    for (auto[mx, nxt] : events) {
        ans = min(ans, mx - mn);
        if (nxt == -1) break;
        mn = min(mn, nxt);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}