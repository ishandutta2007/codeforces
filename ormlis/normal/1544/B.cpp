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
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int h, w;
    cin >> h >> w;
    range(i, h) {
        range(j, w) {
            if (i == 0) {
                if (j & 1) cout << '0';
                else cout << '1';
            } else if (i == h - 1) {
                if (i & 1) {
                    if (j < 2 || (j & 1) || j + 2 >= w) {
                        cout << '0';
                    } else {
                        cout << '1';
                    }
                } else {
                    if (j & 1) {
                        cout << '0';
                    } else {
                        cout << '1';
                    }
                }
            } else {
                if (j > 0 && j < w - 1) {
                    cout << '0';
                } else if (i & 1) {
                    cout << '0';
                } else {
                    cout << '1';
                }
            }
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