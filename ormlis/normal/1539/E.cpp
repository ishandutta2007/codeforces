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
const int maxN = 1e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

bool have(int x, pair<int, int> seg) {
    return seg.first <= x && x <= seg.second;
}

pair<int, int> intersect(pair<int, int> &a, pair<int, int> &b) {
    pair<int, int> c = {max(a.first, b.first), min(a.second, b.second)};
    return c;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<pair<int, int>> l(n), r(n);
    range(i, n) {
        cin >> k[i];
        cin >> l[i].first >> l[i].second;
        cin >> r[i].first >> r[i].second;
    }
    vector<pair<int, int>> dpR(n + 1, {m + 1, -m - 1}), dpL(n + 1, {m + 1, -m - 1});
    dpR[n] = dpL[n] = {0, m};
    vector<bool> nxtL(n, false), nxtR(n, false);
    for (int i = n - 1; i >= 0; --i) {
        if (have(k[i], r[i])) {
            // take right
            if (have(k[i], dpL[i + 1])) {
                // last left
                dpR[i] = l[i];
                nxtR[i] = true;
            } else {
                // last right
                dpR[i] = intersect(l[i], dpR[i + 1]);
            }
        }
        if (have(k[i], l[i])) {
            // take left
            if (have(k[i], dpR[i + 1])) {
                // last right
                dpL[i] = r[i];
                nxtL[i] = true;
            } else {
                // last left
                dpL[i] = intersect(r[i], dpL[i + 1]);
            }
        }
    }
    int current = -1;
    if (have(0, dpL[0])) {
        current = 0;
    } else if (have(0, dpR[0])) {
        current = 1;
    } else {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    range(i, n) {
        cout << current << ' ';
        if ((current == 0 && nxtL[i]) || (current == 1 && nxtR[i])) current ^= 1;
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