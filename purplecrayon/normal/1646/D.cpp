#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

int n;
pair<int, int> dp[N][2];
vector<int> adj[N];
bool use[N];

pair<int, int> get_max(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return min(a, b);
    return max(a, b);
}
void add_self(pair<int, int>& a, pair<int, int> b) {
    a.first += b.first;
    a.second += b.second;
}
void dfs(int c, int p) {
    dp[c][0] = {0, 0}, dp[c][1] = {1, sz(adj[c])};
    for (auto nxt : adj[c]) if (nxt != p) {
        dfs(nxt, c);

        add_self(dp[c][0], get_max(dp[nxt][0], dp[nxt][1]));
        add_self(dp[c][1], dp[nxt][0]);
    }
}
void rec(int c, int p, int me) {
    if (me && dp[c][0] == get_max(dp[c][0], dp[c][1])) me = 0;

    use[c] = me;
    for (auto nxt : adj[c]) if (nxt != p) {
        rec(nxt, c, me ^ 1);
    }
}
void solve() {
    cin >> n;
    if (n == 2) {
        cout << "2 2\n1 1\n";
        return;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0, -1);
    rec(0, -1, 1);

    pair<int, int> ans = get_max(dp[0][0], dp[0][1]);
    cout << ans.first << ' ' << ans.second + n - ans.first << '\n';
    for (int i = 0; i < n; i++) {
        if (use[i]) cout << sz(adj[i]) << ' ';
        else cout << 1 << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}