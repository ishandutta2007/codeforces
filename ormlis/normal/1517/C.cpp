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
    int n; cin >> n;
    vector<int> p(n);
    range(i, n) cin >> p[i];
    vector<vector<pair<int, int>>> kek(n + 1);
    vector<vector<int>> a(n, vector<int> (n));
    for(int d = n; d >= 1; --d) {
        vector<int> ord;
        range(i, n) {
            if (p[i] >= d) ord.push_back(p[i]);
        }
        int t = d - 1;
        // i - j == t
        // i == j + t
        range(j, n - t) {
            a[j+t][j] = ord[j];
            kek[ord[j]].push_back({j+t, j});
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int t = 1; t < kek[i].size(); ++t) {
            if (abs(kek[i][t].first - kek[i][t - 1].first) + abs(kek[i][t].second - kek[i][t - 1].second) > 1) {
                cout << "-1\n";
                return;
            }
        }
    }
    range(i, n) {
        range(j, i + 1) cout << a[i][j] << ' ';
        cout << "\n";
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