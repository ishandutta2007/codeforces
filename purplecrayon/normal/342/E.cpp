#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

struct CentroidDecomp {
    vector<int> adj[MAXN], dist[MAXN];
    int par[MAXN], sub[MAXN], blocked[MAXN];
    void init(){
        memset(par, -1, sizeof(par)); memset(blocked, 0, sizeof(blocked));
    }
    void add(int u, int v){
        adj[u].push_back(v); adj[v].push_back(u);
    }
    void build(int u, int p) {
		int n = dfs(u, p), centroid = dfs(u, p, n);// cout << centroid << endl;
		dfsDist(centroid, -1, 0);
		if (p == -1) p = centroid;
		par[centroid] = p; blocked[centroid] = true;
		for (auto v : adj[centroid]) if (!blocked[v])
			build(v, centroid);
	}
	void dfsDist(int c, int p, int d){
	    dist[c].push_back(d);
	    for (auto nxt : adj[c]) if (nxt != p && !blocked[nxt]) dfsDist(nxt, c, d+1);
	}
	int dfs(int u, int p) {
		sub[u] = 1;
		for (auto v : adj[u]) if (v != p && !blocked[v]) sub[u] += dfs(v, u);
		return sub[u];
	}
	int dfs(int u, int p, int n) {
		for (auto v : adj[u]) if (v != p && sub[v] > n/2 && !blocked[v]) return dfs(v, u, n);
		return u;
	}
	int operator[](int i) {
		return par[i];
	}
} cd;

int n, m, ans[MAXN];

void upd(int c){
    int canc = 0, ori = c;
    while (true){
        // cout << "UPD: " << ori << " " << c << " " << cd.dist[ori][canc] << "\n";
        ans[c] = min(ans[c], cd.dist[ori][canc]);
        if (c == cd[c]) break;
        c = cd[c]; canc++;
    }
}
int qry(int c){
    int ori=c, canc=0;
    int cans = n+1;
    while (true){
        cans = min(cans, cd.dist[ori][canc]+ans[c]);
        if (c == cd[c]) break;
        c = cd[c]; canc++;
    }
    return cans;
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        cd.add(a, b);
    }
    cd.init(); cd.build(0, -1);
    for (int i = 0; i < n; i++){ reverse(cd.dist[i].begin(), cd.dist[i].end()); }
    for (int i = 0; i < n; i++) ans[i] = n+1;
    upd(0);
    while (m--){
        int t; cin >> t;
        if (t == 1){ //upd
            int c; cin >> c, --c; upd(c);
        } else { //qry
            int c; cin >> c, --c;
            cout << qry(c) << "\n";
        }
    }
}