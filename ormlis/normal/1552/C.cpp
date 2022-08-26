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
const int md = 31607;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> to(n * 2, -1);
    vector<pair<int, int>> segs;
    range(i, k) {
        int x, y; cin >> x >> y;
        to[x - 1] = y - 1;
        to[y - 1] = x - 1;
        segs.emplace_back(min(x - 1,  y - 1), max(x - 1, y - 1));
    }
     vector<int> was;
    range(i, n * 2) {
        if (to[i] == -1) was.push_back(i);
    }
    for(int i = k; i < n; ++i) {
        int x = was[i - k];
        int y = was[i - k + (int)was.size() / 2];
        to[x] = y;
        to[y] = x;
        segs.emplace_back(x, y);
    }
    int ans = 0;
    range(i, n) {
        range(j, n) {
            if (segs[i].first >= segs[j].first) continue;
            if (segs[i].second < segs[j].second && segs[j].first < segs[i].second) ans++;
        }
    }
    cout << ans << '\n';
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