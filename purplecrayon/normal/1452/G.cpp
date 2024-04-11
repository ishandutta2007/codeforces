#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, d[MAXN];
vector<int> adj[MAXN];

struct CentDecomp {
    bool blocked[MAXN];
    int par[MAXN], sub[MAXN];
    vector<int> dist[MAXN];
    vector<bool> gAnc[MAXN];
    vector<pair<int, int>> vals[MAXN];
    void dfsDist(int u, int p, int cd, int mx, int centroid){
    	//how do we determine if the path from u to centroid is good
    	//everything from u to centroid must have cd < d[c] -> cd-d[c] < 0
    	//moving down increases cd by one -> maintain the max
    	mx++; mx = max(mx, -d[u]);
//    	cout << centroid << ' ' << u << ' ' << mx << '\n';
		dist[u].push_back(cd);  gAnc[u].push_back(mx < 0);
        for (auto v : adj[u]) if (!blocked[v] && v != p) dfsDist(v, u, cd+1, mx, centroid);
    }
    int dfsSub(int u, int p){
        sub[u] = 1;
        for (auto v : adj[u]) if (v != p && !blocked[v]) sub[u] += dfsSub(v,u);
        return sub[u];
    }
    int dfsCentroid(int u, int p, int sz){
        for (auto v : adj[u]) 
            if (v != p && !blocked[v] && sub[v] > sz/2) return dfsCentroid(v,  u, sz);
        return u;
    }
    void dfsAns(int u, int p, int mn, int cd, int centroid){
        vals[centroid].emplace_back(min(mn, d[u]-cd), d[u]);
        mn = min(mn, d[u]-cd-1);
        for (auto v : adj[u]) if (v != p && !blocked[v]) dfsAns(v, u, mn, cd+1, centroid);
    }
    void bldAns(int centroid){
        sort(vals[centroid].begin(), vals[centroid].end());
        for (int i = sz(vals[centroid])-2; i >= 0; i--) vals[centroid][i].second = max(vals[centroid][i].second, vals[centroid][i+1].second);
    }
    void build(int u, int p){
        int sz = dfsSub(u, p);
        int centroid = dfsCentroid(u, p, sz); //cerr << centroid << '\n';
        if (p == -1) p = centroid;
        par[centroid] = p; blocked[centroid] = 1;
        for (auto nxt : adj[centroid]) if (!blocked[nxt]) {
            dfsDist(nxt, centroid, 1, -1e9, centroid);
        }
        dfsAns(centroid, -1, 1e9, 0, centroid); bldAns(centroid);
        for (auto nxt : adj[centroid]) if (!blocked[nxt]) build(nxt, centroid);
        dist[centroid].push_back(0); gAnc[centroid].push_back(d[centroid]);
    }
    int operator[](int i){ return par[i]; }
} cd;

int dfs1(int c=0, int p=-1){
    for (auto nxt : adj[c]) if (nxt != p) d[c] = min(d[c], 1+dfs1(nxt, c));
    return d[c];
}
void dfs2(int c=0, int p=-1){
    if (c) d[c] = min(d[c], 1+d[p]);
    for (auto nxt : adj[c]) if (nxt != p) dfs2(nxt, c);
}
/*
int dfs3(int c, int p, int cd){
    int ans=0;
    if (cd <= d[c]) ans = max(ans, d[c]); 
    if (cd < d[c]) for (auto nxt : adj[c]) if (nxt != p) ans = max(ans, dfs3(nxt, c, cd+1));
    return ans;
}*/
void solve(){
    cin >> n; fill(d, d+n, MAXN);
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++){
        int a; cin >> a, --a;
        d[a]=0;
    }
    dfs1(), dfs2();
    cd.build(0, -1);
    for (int i = 0; i < n; i++){
		reverse(cd.dist[i].begin(), cd.dist[i].end()), reverse(cd.gAnc[i].begin(), cd.gAnc[i].end());
//		if (i == 1) for (auto it : cd.gAnc[i]) cout << it; cout << '\n';
//		if (cd.gAnc[i].size() != cd.dist[i].size()) cerr << i << ' ' << cd.gAnc[i].size() << ' ' << cd.dist[i].size() << '\n';
		assert(cd.gAnc[i].size() == cd.dist[i].size());
	}
    // min(d[p]-cd-1, d[c]-cd) >= 0
    for (int i = 0; i < n; i++){
        if (d[i] == 0){ cout << "0 "; continue; }
        int c=i, cAnc=0, cAns=0;
        while (1){
            int curd=cd.dist[i][cAnc];
//            for (auto& it : cd.vals[c]) if (it.first >= curd) cAns = max(cAns, it.second);
//			cout << "\nHERE[0] " << c << ' ' << i << ' ' << cAnc << '\n';
//			if (i == 1 && cAnc == 1) cout << "\nHERE " << cd.gAnc[c][cAnc] << '\n';
			if (cd.gAnc[i][cAnc]){
	            int idx=lower_bound(cd.vals[c].begin(), cd.vals[c].end(), make_pair(curd, -INF))-cd.vals[c].begin();
    	        if (idx < sz(cd.vals[c])) cAns = max(cAns, cd.vals[c][idx].second);
			}
            if (c==cd[c]) break;
            c=cd[c], cAnc++;
        }
        cout << cAns << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}