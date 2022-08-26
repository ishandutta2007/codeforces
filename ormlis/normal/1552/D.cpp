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
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<bool> us(n);
    bool ok = false;
    function<void(int, ll)> rec = [&] (int i, ll x) {
        if (i == n) {
            range(j, n) {
                if (us[j]) continue;
                if (a[j] == x) {
                    ok = true;
                }
            }
            return;
        }
        rec(i + 1, x);
        if (ok) return;
        us[i] = true;
        rec(i + 1, x + a[i]);
        if (ok) return;
        rec(i + 1, x - a[i]);
        if (ok) return;
        us[i] = false;
    };
    rec(0, 0);
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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