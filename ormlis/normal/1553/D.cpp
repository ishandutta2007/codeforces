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
    string s;
    cin >> s;
    string t;
    cin >> t;
        int j = 0;
        int cur = (s.size() ^ t.size()) ^ 1;
        range(i, (int) s.size()) {
            if ((cur ^ i) & 1) {
                if (t[j] == s[i]) {
                    j++;
                    cur ^= 1;
                }
            }
            if (j == (int) t.size()) {
                cout << "YES\n";
                return;
            }
        }
    cout << "NO\n";
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