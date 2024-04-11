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
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    {
        auto b = a;
        bool ok = true;
        range(i, n) {
            range(j, m) {
                char need = '.';
                if ((i + j) % 2 == 0) {
                    need = 'R';
                } else {
                    need = 'W';
                }
                if (b[i][j] == '.') b[i][j] = need;
                if (b[i][j] != need) ok = false;
            }
        }
        if (ok) {
            cout << "YES\n";
            range(i, n) cout << b[i] << '\n';
            return;
        }
    }
    {
        auto b = a;
        bool ok = true;
        range(i, n) {
            range(j, m) {
                char need = '.';
                if ((i + j) % 2 == 0) {
                    need = 'W';
                } else {
                    need = 'R';
                }
                if (b[i][j] == '.') b[i][j] = need;
                if (b[i][j] != need) ok = false;
            }
        }
        if (ok) {
            cout << "YES\n";
            range(i, n) cout << b[i] << '\n';
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