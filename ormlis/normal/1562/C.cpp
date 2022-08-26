#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    range(i, n) {
        if (s[i] == '0') {
            if (i > n - 1 - i) {
                cout << "1 " << i + 1 << " " << "1 " << i << "\n";
                return;
            } else {
                cout << i + 1 << " " << n  << " " << i + 2 << " " << n << '\n';
                return;
            }
        }
    }
    int len = n / 2;
    cout << "1 " << len * 2 << " " << "1 " << len << '\n';
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