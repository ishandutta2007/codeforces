#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


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
//const int md = 998244353;
const ll INF = 2e18;
const int maxN = 4000 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int md;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int a[maxN];
int m;

void solve(int l, int r, vector<ll> &res) {
    res.resize(r - l + 1, -INF);
    res[0] = 0;
    int mn = l;
    for(int i = l + 1; i < r; ++i) if (a[mn] > a[i]) mn = i;
    vector<ll> resL = {0};
    vector<ll> resR = {0};
    if (mn != l) solve(l, mn, resL);
    if (mn + 1 != r) solve(mn + 1, r, resR);
    ll w = a[mn];
    range(x, (int)resL.size()) {
        range(y, (int)resR.size()) {
            res[x+y] = max(res[x + y], resL[x] + resR[y] - 1ll * x * y * w * 2);
            res[x+y+1] = max(res[x+y+1], resL[x] + resR[y] - (1ll * (x + 1) * (y + 1) * 2 - 1) * 1ll * w + 1ll * w * m);
        }
    }
}

void solve() {
    int n; cin >> n >> m;
    range(i, n) cin >> a[i];
    vector<ll> result;
    solve(0, n, result);
    cout << result[m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}