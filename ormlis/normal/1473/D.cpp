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

const int INFi = 1e9 + 5;
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> pmx(n + 1), pmn(n + 1), smx(n + 1), smn(n + 1);
    pmx[0] = pmn[0] = 0;
    vector<int> to(n + 1);
    int cur = 0;
    range(i, n) {
        to[i] = cur;
        if (s[i] == '+') cur++;
        else cur--;
        pmx[i + 1] = max(pmx[i], cur);
        pmn[i + 1] = min(pmn[i], cur);
    }
    smx[n - 1] = smn[n - 1] = 0;
    for(int i = n - 1; i >= 1; --i) {
        int t = (s[i] == '+' ? 1 : -1);
        smx[i - 1] = max(0, smx[i] + t);
        smn[i - 1] = min(0, smn[i] + t);
    }
    range(_, m) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        int mn = 0, mx = 0;
        if (l != 0) mn = min(mn, pmn[l]);
        if (l != 0) mx = max(mx, pmx[l]);
        if (r != n - 1) mn = min(mn, to[l] + smn[r]);
        if (r != n - 1) mx = max(mx, to[l] + smx[r]);
        cout << mx - mn + 1 << '\n';
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