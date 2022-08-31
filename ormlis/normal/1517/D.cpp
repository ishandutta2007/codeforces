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
const int maxN = 501;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int to[maxN][maxN][4];
int ans[maxN][maxN][11];

void solve() {
    int n, m; cin >> n >> m;
    int k; cin >> k;
    range(i, n) {
        range(j, m - 1) {
            cin >> to[i][j][0];
            to[i][j + 1][1] = to[i][j][0];
        }
    }
    range(i, n - 1) {
        range(j, m) {
            cin >> to[i][j][3];
            to[i+1][j][2] = to[i][j][3];
        }
    }
    if (k % 2) {
        range(i, n) {
            range(j, m) cout << "-1 ";
            cout << "\n";
        }
        return;
    }
    vector<int> di = {0, 0, -1, 1};
    vector<int> dj = {1, -1, 0, 0};
    k /= 2;
    for(int d = 1; d <= k; ++d) {
        range(i, n) {
            range(j, m) {
                ans[i][j][d] = INFi;
                range(w, 4) {
                    int i1 = i + di[w];
                    int j1 = j + dj[w];
                    if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) continue;
                    ans[i][j][d] = min(ans[i][j][d], to[i][j][w] + ans[i1][j1][d-1]);
                }
            }
        }
    }
    range(i, n) {
        range(j, m) {
            cout << ans[i][j][k] * 2 << ' ';
        }
        cout << '\n';
    }
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