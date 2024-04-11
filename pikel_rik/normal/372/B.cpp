#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 40 + 5;

int n, m;
string grid[N];
int dp[N][N][N][N], query[N][N][N][N];

int recurse(int a, int b, int c, int d) {
    if (a == c and b == d)
        return (grid[a][b] == '0');

    if (query[a][b][c][d] != -1)
        return query[a][b][c][d];

    int ans = dp[a][b][c - a + 1][d - b + 1];
    if (a == c)
        ans += recurse(a, b + 1, c, d);
    else if (b == d)
        ans += recurse(a + 1, b, c, d);
    else ans += recurse(a + 1, b, c, d) + recurse(a, b + 1, c, d) - recurse(a + 1, b + 1, c, d);

    return query[a][b][c][d] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(query, -1, sizeof(query));

    int q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) cin >> grid[i];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            for (int l1 = 1; l1 <= n - i; l1++) {
                for (int l2 = 1; l2 <= m - j; l2++) {
                    if (l1 == 1 and l2 == 1)
                        dp[i][j][l1][l2] = (grid[i][j] == '0');
                    else if (l1 == 1)
                        dp[i][j][l1][l2] = (grid[i][j] == '0') & dp[i][j + 1][l1][l2 - 1];
                    else if (l2 == 1)
                        dp[i][j][l1][l2] = (grid[i][j] == '0') & dp[i + 1][j][l1 - 1][l2];
                    else dp[i][j][l1][l2] = (grid[i][j] == '0') & dp[i + 1][j][l1 - 1][l2] & dp[i][j + 1][l1][l2 - 1] & dp[i + 1][j + 1][l1 - 1][l2 - 1];
                }
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            for (int l1 = 1; l1 <= n - i; l1++) {
//                for (int l2 = 1; l2 <= m - j; l2++) {
//                    cout << i << " " << j << " " << l1 << " " << l2 << " " << dp[i][j][l1][l2] << "\n";
//                }
//            }
//        }
//    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l1 = 1; l1 <= n - i; l1++) {
                for (int l2 = 1; l2 <= m - j; l2++) {
                    dp[i][j][l1][l2] += dp[i][j][l1-1][l2] + dp[i][j][l1][l2-1] - dp[i][j][l1-1][l2-1];
                }
            }
        }
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d; --a; --b; --c; --d;

        cout << recurse(a, b, c, d) << "\n";
    }
    return 0;
}