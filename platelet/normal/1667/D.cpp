#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int T, n;
vector<int> G[N];
bool co[N];

bool dfs(int u, int fa) {
    int c[2] = {};
    for(int v : G[u]) if(v != fa) if(dfs(v, u)) return 1; else c[co[v]]++;
    if(u > 1) c[co[u] = c[0] >= c[1]]++;
    return c[1] + c[0] >> 1 != c[0];
}
void Dfs(int u, int fa) {
    vector<int> b[2];
    for(int v : G[u]) b[co[v == fa ? u : v]].pb(v);
    for(bool p = G[u].size() & 1; b[p].size(); p ^= 1) {
        int v = b[p].back(); b[p].pop_back();
        if(v == fa) cout << u << ' ' << fa << '\n'; else Dfs(v, u);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 1, n) G[i].clear();
        int u, v;
        rep(i, 2, n) cin >> u >> v, G[u].pb(v), G[v].pb(u);
        if(dfs(1, 0)) cout << "NO\n";
        else cout << "YES\n", Dfs(1, 0);
    }
}