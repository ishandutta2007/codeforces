#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int MAXK = 1e2+10;

int n, m, k, s;
int a[MAXN], dist[MAXK][MAXN];
vector<int> adj[MAXN];

void solve(){
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    for (int col = 0; col < k; col++) {
        queue<int> q;

        fill(dist[col], dist[col]+n, MOD);
        for (int j = 0; j < n; j++) if (a[j] == col) {
            q.push(j);
            dist[col][j] = 0;
        }
        while (sz(q)) {
            int c = q.front(); q.pop();
            for (auto nxt : adj[c]) if (dist[col][nxt] > dist[col][c]+1) {
                q.push(nxt);
                dist[col][nxt] = dist[col][c]+1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> cur; cur.reserve(k);
        for (int j = 0; j < k; j++) cur.push_back(dist[j][i]);
        sort(cur.begin(), cur.end());
        ll ans = 0;
        for (int i = 0; i < s; i++) ans += cur[i];
        cout << ans << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}