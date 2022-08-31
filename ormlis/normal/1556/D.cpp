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
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    auto ask1 = [&] (int i, int j) {
        i++;
        j++;
        cout << "or " << i << ' ' << j << endl;
        int x; cin >> x;
        return x;
    };
    auto ask2 = [&] (int i, int j) {
        i++;
        j++;
        cout << "and " << i << ' ' << j << endl;
        int x; cin >> x;
        return x;
    };
    auto ask = [&] (int i, int j) {
        ll orr = ask1(i, j);
        ll andd = ask2(i, j);
        return andd + orr;
    };
    vector<ll> a(n);
    ll ab = ask(0, 1);
    ll bc = ask(1, 2);
    ll ac = ask(0, 2);
    ll abc = (ab + bc + ac) / 2;
    a[0] = abc - bc;
    a[1] = abc - ac;
    a[2] = abc - ab;
    for(int i = 3; i < n; ++i) {
        a[i] = ask(i - 1, i) - a[i - 1];
    }
    sort(all(a));
    cout << "finish " << a[k - 1] << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}