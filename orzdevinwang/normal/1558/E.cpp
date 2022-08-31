#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 4007, inf = 1e9 + 5;
int n, m, a[N], b[N], lst[N];
vi adj[N];
ll dis[N];
bool rns[N];
bool SPFA(ll &w) {
	queue < int > q;
	L(i, 1, n) 
		if(rns[i]) q.push(i), dis[i] = w, lst[i] = -1;
		else dis[i] = -1, lst[i] = -1; 
	while (!q.empty()) {
		int u = q.front ();
		q.pop();
		for(int v : adj[u]) if(a[v] < dis[u] && ! (rns[u] && rns[v]) && lst[u] != v) {
			if(dis[v] == -1) dis[v] = dis[u] + b[v], lst[v] = u, q.push(v); 
			else {
				for(int x = u; !rns[x]; x = lst[x]) w += b[x], rns[x] = true;
				for(int x = v; !rns[x]; x = lst[x]) w += b[x], rns[x] = true;
				return true;
			}
		}
	}
	return false;
}
bool check (ll x) {
	L(i, 1, n) rns[i] = i == 1;
	while (SPFA(x)) ;
	L(i, 1, n) if(!rns[i]) return false;
	return true;
}
void Main () {
	cin >> n >> m;
	L(i, 2, n) cin >> a[i];
	L(i, 2, n) cin >> b[i];
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	int l = 0, r = 1e9 + 3, ns = -1; 
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, r = mid - 1;
		else l = mid + 1;
	} 
	cout << ns << "\n";
	L(i, 1, n) adj[i].clear ();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie (0); cout.tie (0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}