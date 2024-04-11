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
    int n;
    cin >> n;
    vector<int> d(n);
    range(i, n) cin >> d[i];
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return d[i] > d[j];
    });
    vector<pair<int, int>> answ;
    ord[0] *= 2;
    for (int i = 1; i < n; ++i) {
        ord[i] *= 2;
        answ.emplace_back(ord[i], ord[i - 1]);
    }
    range(i, n) {
        int v = ord[i] / 2;
        int to = d[v] + i;
        if (to == (int) ord.size()) {
            answ.emplace_back(ord.back(), v * 2 + 1);
            ord.push_back(v * 2 + 1);
            continue;
        }
        answ.emplace_back(ord[to - 1], v * 2 + 1);
    }
    for(auto &[x, y] : answ) cout << x + 1 << ' ' << y + 1 << '\n';
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