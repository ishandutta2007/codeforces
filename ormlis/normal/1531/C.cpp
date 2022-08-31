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
const int maxN = 1e3 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    for(int m = 1; m <= 100; ++m) {
        if (m * m < n) continue;
        vector<vector<char>> a(m, vector<char> (m, 'o'));
        if (m * m == n) {
            cout << m << '\n';
            range(i, m) {
                range(j, m) {
                    cout << a[i][j];
                }
                cout << '\n';
            }
            return;
        }
        for(int w = 1; w < m; ++w) {
            int cur = m * m - w * w;
            if (cur < n) break;
            range(i, w) a[i][w - 1] = a[w - 1][i] = '.';
            if ((cur - n) % 2) continue;
            int can = (m - 1 - w) * 2;
            if (cur - can > n) continue;
            for(int i = w; i < m; ++i) {
                if (cur == n) break;
                cur -= 2;
                a[i][0] = '.';
                a[0][i] = '.';
            }
            if (cur != n) continue;
            cout << m << '\n';
            range(i, m) {
                for(int j = m - 1; j >= 0; --j) {
                    cout << a[i][j];
                }
                cout << '\n';
            }
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}