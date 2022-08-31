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
const int maxN = 3e5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> us(n, vector<bool> (m));
    vector<vector<int>> b(n, vector<int> (m));
    vector<ar<int, 3>> a;
    range(i, n) {
        range(j, m) {
            int x; cin >> x;
            a.push_back({x, i, j});
            b[i][j] = x;
        }
    }
    vector<vector<int>> ans(n, vector<int> (m));
    sort(all(a));
    range(w, m) {
        auto [x, i, j] = a[w];
        us[i][j] = true;
        ans[i][w] = x;
    }
    range(i, n) {
        int w = 0;
        range(j, m) {
            if (!ans[i][j]) {
                while (us[i][w]) w++;
                ans[i][j] = b[i][w];
                us[i][w] = true;
            }
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
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