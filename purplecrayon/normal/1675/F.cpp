#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const int INF = MOD;

int n, k;
int x, y;
bool a[N];
vector<int> adj[N];
int ret = 0;

pair<bool, bool> dfs(int c, int p) {
    pair<bool, bool> ans{a[c] || c == y, c == y};
    for (auto nxt : adj[c]) if (nxt != p) {
        auto v = dfs(nxt, c);
        ans.first |= v.first;
        ans.second |= v.second;
    }
    if (p != -1 && ans.first) ret += 2;
    if (ans.second) ret--;
    return ans;
}
void solve() {
    cin >> n >> k;
    cin >> x >> y, --x, --y;
    for (int i = 0; i < n; i++) adj[i].clear(), a[i] = 0;
    for (int i = 0; i < k; i++) {
        int c; cin >> c, --c;
        a[c] = 1;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    ret = 0;
    dfs(x, -1);
    cout << ret + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}