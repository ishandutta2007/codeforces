#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


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

void print(ll x) {
    cout << x / 2 << '.';
    if (x % 2) cout << '5';
    else cout << "0";
    cout << '\n';
}

void solve() {
    ll k, d, t;
    cin >> k >> d >> t;
    t *= 2;
    if (k > d) {
        ll ct = (k + d - 1) / d;
        d *= ct;
    }
    ll cnt = t / (d + k);
    t %= (d + k);
    if (t <= 2 * k) {
        print(cnt * 2 * d + t);
    } else {
        print(cnt * 2 * d + t * 2 - k * 2);
    }
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