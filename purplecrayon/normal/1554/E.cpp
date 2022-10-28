#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

int n;
vector<int> adj[MAXN];
bool work[MAXN], ans[MAXN];

int dfs(int c, int p, int k) {
    int me = 0;
    for (auto nxt : adj[c]) if (nxt != p) {
        int they = dfs(nxt, c, k);
        if (they == -1) return -1;
        assert(they == 0 || they == 1);
        me += they;
    }
    if ((me+1)%k == 0) return 0;
    if (me%k == 0) return 1;
    return -1;
}
void solve(){
    cin >> n;
    for (int i = 0; i <= n; i++) adj[i].clear(), ans[i] = work[i] = 0;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    for (int i = 2; i <= n; i++) if ((n-1)%i == 0) {
        work[i] = dfs(0, -1, i) == 1;
    }
    int cur = 1;
    for (int i = 0; i < n-1; i++) cur = cur*2%MOD;

    for (int i = 2; i <= n; i++) {
        ans[i] = work[i];
        for (int j = 2*i; j <= n; j += i) ans[i] &= !work[j];

        cur -= ans[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << cur;
        else cout << ' ' << ans[i];
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}