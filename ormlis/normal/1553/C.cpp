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
    string s; cin >> s;
    int mn = 0;
    int mx = 0;
    range(i, (int)s.size()) {
        if (i & 1) {
            if (s[i] == '1') {
                mn++;
                mx++;
            } else if (s[i] == '?') {
                mx++;
            }
        } else {
            if (s[i] == '1') {
                mn--;
                mx--;
            } else if (s[i] == '?') {
                mn--;
            }
        }
        int to1 = (int)s.size() / 2 - (int)(i + 1) / 2;
        if (to1 + mn < 0) {
            cout << i + 1 << '\n';
            return;
        }
        int to2 = (int)s.size() - (i + 1) - to1;
        if (mx - to2 > 0) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << (int)s.size() << '\n';
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