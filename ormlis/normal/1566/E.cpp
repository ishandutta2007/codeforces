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
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
vector<int> a;

int dfs(int v, int p) {
    int cnt = 0;
    for (auto &u : g[v]) {
        if (u == p) continue;
        int x = dfs(u, v);
        if (x == 0) {
            cnt++;
        } else {
            a.push_back(x);
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }
    a.clear();
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int kek = dfs(1, -1);
    int ans = accumulate(all(a), 0) + kek;
    sort(all(a));
    int r = (int) a.size() - 1;
    int have = 0;
    for(int l = 0; l <= r; ++l) {
        if (kek) {
            kek--;
            ans--;
            have += a[l];
            continue;
        }
        while(have == 0 && r > l) {
            have += a[r];
            r--;
        }
        if (have == 0) break;
        have--;
        ans--;
        have += a[l];
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