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
const int maxN = 3e5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    bitset<maxN * 2> b;
    b[maxN] = 1;
    range(i, n) {
        cin >> a[i];
        b = (b << a[i]) | (b >> a[i]);
    }
    if (b[maxN] == 0) {
        cout << "0\n";
        return;
    }
    int g = 1 << 20;
    range(i, n) {
        g = __gcd(g, a[i]);
    }
    cout << "1\n";
    range(i, n) {
        if (a[i] % g == 0 && a[i] % (2 * g) != 0) {
            cout << i + 1 << ' ';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}