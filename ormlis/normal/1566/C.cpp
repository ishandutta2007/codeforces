#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    int ans = 0;
    vector<string> a(2);
    range(i, 2) cin >> a[i];
    bool have0 = false, have1 = false;
    range(i, n) {
        bool new0 = (a[0][i] == '0') | (a[1][i] == '0');
        bool new1 = (a[0][i] == '1') | (a[1][i] == '1');
        if (new0 && new1) {
            if (have0) {
                ans++;
                if (have1) {
                    ans++;
                }
            }
            ans += 2;
            have0 = false;
            have1 = false;
            continue;
        }
        if (new0 && have0) {
            ans++;
            have0 = new0;
            have1 = new1;
            continue;
        }
        if (new0) {
            if (have1) {
                ans += 2;
                have0 = false;
                have1 = false;
                continue;
            }
            have0 = true;
            have1 = false;
            continue;
        }
        if (have0) {
            ans += 2;
            have0 = false;
            have1 = false;
            continue;
        }
        assert(new1);
        have1 = new1;
    }
    if (have0) {
        ans++;
        if (have1) ans++;
    }
    cout << ans << '\n';
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