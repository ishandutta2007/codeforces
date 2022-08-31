
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

int n;
string s;
vector<int> adj[N];

int ans = 0;
int dfs(int c) {
    int sub = s[c] == 'B' ? +1 : -1;
    for (auto nxt : adj[c]) sub += dfs(nxt);
    if (sub == 0) ans++;
    return sub;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    cin >> s;
    ans = 0;
    dfs(0);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}