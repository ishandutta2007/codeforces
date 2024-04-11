#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 5001;
ll md = 1000000007;

vector<pair<int, int>> g[maxN];
int color[maxN];

int dfs(int v, int p, int c, int to) {
    if (v == to) {
        return 1;
    }
    for(auto u: g[v]) {
        if (u.first == p) continue;
        if (dfs(u.first, v, c, to)) {
            color[u.second] = max(c, color[u.second]);
            return 1;
        }
    }
    return 0;
}

int check_dfs(int v, int p, int to) {
    if (v == to) {
        return 1e9;
    }
    for(auto u: g[v]) {
        if (u.first == p) continue;
        int k = check_dfs(u.first, v, to);
        if (k != -1) {
            k = min(k, color[u.second]);
            return k;
        }
    }
    return -1;
}

void solve() {
    int n, m; cin >> n;
    range(i, n - 1) {
        int x, y; cin >> x >> y;
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
    }
    cin >> m;
    vector<ar<int, 3>> s;
    range(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        dfs(a, -1, c, b);
        s.push_back({a, b, c});
    }
    range(i, m) {
        if (check_dfs(s[i][0], -1, s[i][1]) != s[i][2]) {
            cout << "-1";
            return;
        }
    }
    range(i, n - 1) {
        cout << max(color[i], 1) << ' ';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}