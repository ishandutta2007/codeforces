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
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    range(i, n / 2) {
        range(j, n / 2) {
            int t = i * (n / 2) + j;
            int x = t * 4;
            a[i * 2][j * 2] = x;
            a[i * 2 + 1][j * 2] = x + 3;
            a[i * 2][j * 2 + 1] = x + 1;
            a[i * 2 + 1][j * 2 + 1] = x + 2;
        }
    }
    range(i, n) {
        range(j, n) cout << a[i][j] << ' ';
        cout << '\n';
    }
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