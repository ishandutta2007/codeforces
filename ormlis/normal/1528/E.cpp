#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
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

void solve() {
    int n; cin >> n;
    n++;
    vector<int> dp1(n + 1);
    vector<int> dp2(n + 1);
    dp1[1] = 1;
    dp2[1] = 1;
    auto with2 = [&] (int h) {
        if (h == 1) return 0;
        int res = mul(dp2[h - 1], dp2[h - 1]);
        res = sub(res, mul(dp2[h - 2], dp2[h - 2]));
        res = add(res, dp1[h - 1]);
        res = mul(res, rev(2));
        return res;
    };
    auto with3 = [&] (int h) {
        if (h == 1) return 0;
        int res1 = mul(dp1[h - 1], mul(mul(dp2[h - 2], add(dp2[h - 2], 1)), rev(2)));
        int res2 = mul(mul(mul(dp1[h - 1], add(dp1[h - 1], 1)), rev(2)), dp2[h - 2]);
        int res3 = mul(mul(dp1[h - 1], sub(dp1[h - 1], 1)), sub(dp1[h - 1], 2));
        res3 = mul(res3, rev(6));
        res3 = add(res3, mul(dp1[h - 1], dp1[h - 1]));
        return add(add(res3, res2), res1);
    };
    for(int i = 2; i <= n; ++i) {
        dp1[i] = add(dp1[i - 1], with2(i));
        dp2[i] = add(dp1[i], dp2[i - 1]);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int h = n - i;
        int right = 1;
        if (i + 1 < n) {
            right = with2(h);
        }
        if (i == 0) right = add(right, with3(h));
        int left = 1;
        if (i) {
            left = dp1[i];
        }
        if (i + 1 == n) {
            left = add(dp1[n], with3(n));
        }
        ans = add(ans, mul(left, right));
    }
    cout << ans;
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