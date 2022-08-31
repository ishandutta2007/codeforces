#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;*/
int n;
vector<int> g[5000001];
int used[5000001];
pair<int, int> ans[500001];

int dfs(int v, int l, int r) {
    used[v] = 1;
    l -= g[v].size();
    ans[v].second = r;
    ans[v].first = l;
    int left = l;
    int right = l;
    for(auto u: g[v]) {
        if (!used[u]) {
            right++;
            left = dfs(u, left, right);
        }
    }
    return left;
}


void solve() {
    cin >> n;
    range(i, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 2 * n - 1, 2 * n);
    for(int i = 1; i <= n; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}