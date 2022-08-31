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
const int LG = 20;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int up[maxN][LG];
int a[maxN];
int c[maxN];

ll result = 0;
void go(int v, int j, int &w) {
    if (a[v] == 0) return;
    for(j--; j >= 0; --j) {
        if (!w) return;
        go(up[v][j], j, w);
    }
    int x = min(w, a[v]);
    result += 1ll * c[v] * x;
    a[v] -= x;
    w -= x;
}

void solve() {
    int q; cin >> q >> a[0] >> c[0];
    for(int i = 1; i <= q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            cin >> up[i][0] >> a[i] >> c[i];
            for(int j = 1; j < LG; ++j) up[i][j] = up[up[i][j - 1]][j - 1];
        } else {
            int v, w; cin >> v >> w;
            result = 0;
            int was = w;
            go(v, LG, w);
            cout << was - w << ' ' << result << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}