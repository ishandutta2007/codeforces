#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(v) int(v.size())

const int MAXN = 2e5+10, MAXL = 18;

int n, m, s;
int depth[MAXN], anc[MAXN][MAXL];

int jmp(int a, int h){
	for (int i = 0; i < MAXL; i++) if ((h>>i)&1) a = anc[a][i];
	return a;
}
int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(a, depth[a]-depth[b]);
	if (a==b) return a;
	for (int i = MAXL-1; i >= 0; i--){
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0]==anc[b][0]);
	return anc[a][0];
}

const int mxN=2e5+10;
const ll INF=1e18;
ll d[mxN];
vector<ar<int, 2>> adj[mxN];
bool vis[mxN];
vector<int> adj2[mxN], badj2[mxN];
vector<int> adj3[mxN];

int dp[mxN];
int rec(int c) {
    if (dp[c] != -1) return dp[c];
    int ans=1;
    for (auto nxt : adj3[c]) ans += rec(nxt);
    return dp[c] = ans;
}
int solve() {
    memset(anc, -1, sizeof(anc));
    vector<int> top(n); iota(top.begin(), top.end(), 0);
    sort(top.begin(), top.end(), [&](int a, int b){ return d[a] < d[b]; });
    memset(anc, -1, sizeof(anc));
    depth[s] = 0;
    for (int c : top) if (c != s && d[c] < INF) {
        if (!sz(badj2[c])) continue;

        int l=badj2[c][0];
        for (int p : badj2[c]) {
            l = lca(l, p);
        }
        adj3[l].push_back(c);
        anc[c][0] = l;
        depth[c] = depth[l]+1;
        for (int i = 1; i < MAXL; i++) anc[c][i] = (anc[c][i-1] == -1 ? -1 : anc[anc[c][i-1]][i-1]);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++) if (i != s && d[i] < INF) {
        ans = max(ans, rec(i));
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s, --s;
    for (int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(d, 0x3f, sizeof(d));
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    pq.push({d[s]=0, s});
    while(!pq.empty()) {
        int u=pq.top()[1];
        pq.pop();
        if (vis[u])
            continue;
        vis[u]=1;
        for (ar<int, 2> v : adj[u])
            if (d[u]+v[1]<d[v[0]])
                pq.push({d[v[0]]=d[u]+v[1], v[0]});
    }
    for (int i=0; i<n; ++i) {
        if (d[i]>=INF)
            continue;
        for (ar<int, 2> j : adj[i])
            if (d[i]+j[1]==d[j[0]])
                adj2[i].push_back(j[0]), badj2[j[0]].push_back(i);
    }
    cout << solve() << '\n';
    return 0;
}