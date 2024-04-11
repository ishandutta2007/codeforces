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

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 31607;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<ar<int, 5>> r(n);
    range(i, n) {
        range(j, 5) cin >> r[i][j];
    }
    auto check = [&] (int i, int j) {
        int cnt = 0;
        range(w, 5) {
            if (r[i][w] < r[j][w]) cnt++;
        }
        return cnt >= 3;
    };
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if (!check(ans, i)) ans = i;
    }
    range(i, n) {
        if (i == ans) continue;
        if (!check(ans, i)) {
            cout << "-1\n";
            return;
        }
    }
    cout << ans + 1 << '\n';
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