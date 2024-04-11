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
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<ll> s(n);
    vector<int> p(n);
    for(int i = 1; i < n; ++i) {
        int x; cin >> x;
        x--;
        p[i] = x;
    }
    range(i, n) cin >> s[i];
    for(int i = 1; i < n; ++i) {
        if (s[i] != -1) {
            s[p[i]] = min(s[p[i]], s[i]);
        } else {
            s[i] = INF;
        }
    }
    ll ans = s[0];
    for(int i = 1; i < n; ++i) {
        if (s[i] != INF) {
            if (s[i] < s[p[i]]) {
                cout << "-1\n";
                return;
            }
            ans += s[i] - s[p[i]];
        }
    }
    cout << ans << '\n';
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