#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const int L = 19;

int n, depth[N], anc[N][L];
vector<int> adj[N];

void dfs_lca(int c, int p, int d) {
	depth[c] = d, anc[c][0] = p;
	for (int i = 1; i < L; i++) anc[c][i] = (anc[c][i-1] == -1 ? -1 : anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) dfs_lca(nxt, c, d+1);
}
int jump(int a, int h) {
	for (int i = 0; i < L; i++) if ((h >> i) & 1) a = anc[a][i];
	return a;
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jump(a, depth[a]-depth[b]);
	if (a == b) return a;
	for (int i = L-1; i >= 0; i--) {
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0] == anc[b][0]);
	return anc[a][0];
}
int dist(int a, int b) {
    if (min(a, b) == -1) return -MOD;
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs_lca(0, -1, 0);
    vector<vector<int>> me(n + 1);
    vector<int> ans(n + 1, n);
    for (int i = 0; i < n; i++) me[depth[i]].push_back(i);
    ar<int, 2> diam{-1, -1};
    for (int i = n - 1; i >= 0; i--) {
        int can = min(n, i - (dist(diam[0], diam[1]) + 1) / 2);
        if (can >= 0) {
            ans[can] = min(ans[can], i);
        }

        for (int c : me[i]) {
            for (ar<int, 2> new_diam : {ar<int, 2>{diam[0], c}, ar<int, 2>{diam[1], c}, {c, c}}) {
                if (dist(new_diam[0], new_diam[1]) >= dist(diam[0], diam[1])) {
                    diam = new_diam;
                }
            }
        }
    }
    for (int x = n-1; x >= 1; x--) ans[x] = min(ans[x], ans[x+1]);
    for (int x = 1; x <= n; x++) cout << ans[x] << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}