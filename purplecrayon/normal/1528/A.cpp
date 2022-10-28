#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

int n;
ar<ll, 2> a[MAXN];
vector<int> adj[MAXN];

ar<ll, 2> dfs(int c=0, int p=-1) {
    ar<ll, 2> ans{0, 0};
    for (auto nxt : adj[c]) if (nxt != p) {
        ar<ll, 2> they = dfs(nxt, c);
        ans[0] += max(they[0]+abs(a[c][0]-a[nxt][0]), they[1]+abs(a[c][0]-a[nxt][1]));
        ans[1] += max(they[0]+abs(a[c][1]-a[nxt][0]), they[1]+abs(a[c][1]-a[nxt][1]));
    }
    return ans;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    ar<ll, 2> ans = dfs();
    cout << max(ans[0], ans[1]) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}