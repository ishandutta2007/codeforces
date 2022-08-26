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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> c(n);
    auto ask = [&](int x) {
        cout << x << endl;
        int r;
        cin >> r;
        return r;
    };
    range(i, n) {
        c[i] = ask(1);
        if (c[i] == 0) return;
    }
    int l = 1, r = m + 1;
    int t = 0;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        int d = ask(mid) * c[t];
        if (d == 0) break;
        if (d == -1) {
            r = mid;
        } else {
            l = mid;
        }
        t = (t + 1) % n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}