#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 4e5 + 5;
int fact[maxF];
int rfact[maxF];

void initF() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> x(n), y(m);
    range(i, n) cin >> x[i];
    range(i, m) cin >> y[i];
    vector<pair<int, int>> badx, bady;
    ll ans = 0;
    range(i, k) {
        int xx, yy; cin >> xx >> yy;
        int j = lower_bound(all(x), xx) - x.begin();
        if (j == n || x[j] != xx) {
            badx.push_back({xx, yy});
        }
        j = lower_bound(all(y), yy) - y.begin();
        if (j == m || y[j] != yy) {
            bady.push_back({yy, xx});
        }
    }
    range(_, 2) {
        sort(all(badx));
        for(int i = 1; i < x.size(); ++i) {
            int l = lower_bound(all(badx), pair<int, int>{x[i - 1], -INFi}) - badx.begin();
            int r = lower_bound(all(badx), pair<int, int>{x[i], -INFi}) - badx.begin();
            ans += 1ll * (r - l) * (r - l - 1) / 2;
            map<int, int> cnt;
            for(int j = l; j < r; ++j) {
                ans -= cnt[badx[j].second]++;
            }
        }
        swap(badx, bady);
        swap(x, y);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    initF();
    range(_, tests) {
        solve();
    }
    return 0;
}