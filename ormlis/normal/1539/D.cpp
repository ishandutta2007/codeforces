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
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    range(i, n) cin >> a[i].second >> a[i].first;
    sort(all(a));
    int j = n - 1;
    ll have = 0;
    ll ans = 0;
    range(i, n) {
        while(j >= i && have < a[i].first) {
            ll need = min(a[j].second, a[i].first - have);
            have += need;
            ans += need * 2;
            a[j].second -= need;
            if (a[j].second == 0) j--;
        }
        ll c = 1;
        if (have < a[i].first) c *= 2;
        ans += a[i].second * c;
        have += a[i].second * c;
        a[i].second = 0;
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