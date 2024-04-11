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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    range(i, n) {
        range(j, m) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    vector<vector<int>> p(n, vector<int>(m));
    range(i, n) {
        range(j, m) {
            p[i][j] = a[i][j];
            if (i) p[i][j] += p[i - 1][j];
            if (j) p[i][j] += p[i][j - 1];
            if (i && j) p[i][j] -= p[i - 1][j - 1];
        }
    }
    auto get = [&](int l1, int r1, int l2, int r2) {
        int result = p[r1][r2];
        if (l1) result -= p[l1 - 1][r2];
        if (l2) result -= p[r1][l2 - 1];
        if (l1 && l2) result += p[l1 - 1][l2 - 1];
        return result;
    };

    auto get2 = [&](int l1, int r1, int l2, int r2) {
        int w = (r1 - l1 + 1) * (r2 - l2 + 1);
        return w - get(l1, r1, l2, r2);
    };
    int ans = INFi;

    for (int l = 0; l < m; ++l) {
        for (int r = l + 3; r < m; ++r) {
            int mn = INFi;
            for (int up = 0; up < n; ++up) {
                int dw = up - 4;
                if (dw >= 0) {
                    int cur = get(dw + 1, up - 1, l + 1, r - 1);
                    cur += get2(dw + 1, up - 1, l, l);
                    cur += get2(dw + 1, up - 1, r, r);
                    cur += get2(dw, dw, l + 1, r - 1);
                    mn = min(mn, cur);
                }
                if (mn != INFi) {
                    int cur = get2(up, up, l + 1, r - 1);
                    ans = min(ans, cur + mn);
                    mn += get(up, up, l + 1, r - 1);
                    mn += get2(up, up, l, l);
                    mn += get2(up, up, r, r);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}