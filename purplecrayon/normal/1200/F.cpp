#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

const int MAXA = 2520;

int n;
vector<int> adj[MAXN];
ar<int, 2> nxt[MAXN][MAXA];
ll a[MAXN];
int ans[MAXN][MAXA];
bool vis[MAXN][MAXA], cycle_start[MAXN][MAXA];
ar<int, 2> cycle_marked[MAXN][MAXA];

int get(ll x){ return ((x%MAXA)+MAXA)%MAXA; }
int rec(int i, int j) {
    if (ans[i][j] != -1) return ans[i][j];
    return ans[i][j] = rec(nxt[i][j][0], nxt[i][j][1]);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        adj[i].resize(m);
        for (auto& c : adj[i]) cin >> c, --c;
    }
    for (int i = 0; i < n; i++) {
        int deg = sz(adj[i]);
        for (int j = 0; j < MAXA; j++) {
            nxt[i][j] = {adj[i][get(j+a[i])%deg], get(j+a[i])};
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < MAXA; j++) if (!vis[i][j]) {
        ar<int, 2> c{i, j};
        while (!vis[c[0]][c[1]]) {
            cycle_marked[c[0]][c[1]] = {i, j};
            vis[c[0]][c[1]] = 1;
            c = nxt[c[0]][c[1]];
        }
        if (cycle_marked[c[0]][c[1]] == ar<int, 2>{i, j}) 
            cycle_start[c[0]][c[1]] = 1;
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++) for (int j = 0; j < MAXA; j++) if (cycle_start[i][j]) {
        ar<int, 2> c{i, j};

        static int has[MAXN], tt=0;
        tt++;

        int cur = 0;
        do {
            cur += has[c[0]] != tt, has[c[0]] = tt;
            c = nxt[c[0]][c[1]];
        } while (c != ar<int, 2>{i, j});
        do {
            ans[c[0]][c[1]] = cur;
            c = nxt[c[0]][c[1]];
        } while (c != ar<int, 2>{i, j});
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < MAXA; j++) rec(i, j);
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y, --x;
        cout << ans[x][get(y)] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}