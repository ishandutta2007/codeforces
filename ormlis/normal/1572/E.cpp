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
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct pt {
    ll x, y;
};

pt operator-(const pt &a, const pt &b) {
    return {a.x - b.x, a.y - b.y};
}

ll operator*(const pt &a, const pt &b) {
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

ll operator%(const pt &a, const pt &b) {
    return 1ll * a.x * b.x + a.y * b.y;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pt> a(n);
    range(i, n) cin >> a[i].x >> a[i].y;
    auto square = [&](int i, int j, int e) {
        ll res = (a[j] - a[i]) * (a[e] - a[i]);
        return abs(res);
    };
    auto check = [&](ll x) {
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<ll>> dp2(n, vector<ll>(n, -1));
        range(r, n) {
            for (int l = r - 1; l >= 0; --l) {
                if (l + 1 == r) {
                    dp1[l][r] = 0;
                    dp2[l][r] = 0;
                    continue;
                }
                /*if (l + 2 == r) {
                    ll s = square(l, l + 1, r);
                    if (s >= x) {
                        dp1[l][r] = 1;
                        dp2[l][r] = 0;
                    } else {
                        dp1[l][r] = 0;
                        dp2[l][r] = s;
                    }
                    continue;
                }*/
                for (int mid = l + 1; mid < r; ++mid) {
                    int t = 1;
                    if (mid != l + 1) {
                        if (dp1[l][mid] == 0) continue;
                        t += dp1[l][mid];
                    }
                    t += dp1[mid][r];
                    ll s = square(l, mid, r) + dp2[mid][r];
                    if (s >= x) {
                        if (dp1[l][r] < t) {
                            dp1[l][r] = t;
                            dp2[l][r] = 0;
                        }
                        continue;
                    }
                    t--;
                    if (dp1[l][r] < t) {
                        dp1[l][r] = t;
                        dp2[l][r] = s;
                    } else if (dp1[l][r] == t) {
                        dp2[l][r] = max(dp2[l][r], s);
                    }
                }
            }
        }
        return dp1[0][n - 1] - 1 >= k;
    };
    ll R = 1;
    for(int i = 2; i < n; ++i) {
        R += square(0, i - 1, i);
    }
    ll L = -1;
    while(R - L > 1) {
        ll mid = (R + L) / 2;
        if (check(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    assert(L != -1);
    cout << L << '\n';
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