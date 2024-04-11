#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7;
int n, m, tp, dis[N];
vi e[N][10];
int su[N], sv[N];
void Add (int u, int v, int w) {
	if(w <= 9) return e[u][w].push_back(v);
	++tp, e[tp][w % 10].push_back(v), w /= 10;
	while (w >= 10) ++tp, e[tp][w % 10].push_back(tp - 1), w /= 10;
	e[u][w].push_back(tp);
}
bool vis[N];
int D[N];
void dfs (vi S) {
	L(i, 0, 9) {
		vi cS;
		for (const int &t : S) for (const int &z : e[t][i]) {
			if(!vis[z] && dis[z] == dis[t] + 1) 
				vis[z] = true, D[z] = ((ll) D[t] * 10 + i) % mod, cS.push_back(z);	
		}
		if(sz(cS)) dfs (cS);
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m, tp = n;	
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		Add (u, v, i);
		Add (v, u, i);
	}
	queue < int > q;
	q.push(1), dis[1] = 1;
	while (!q.empty()) {
		int u = q.front ();
		q.pop () ;
		L(i, 0, 9) for (const int &v : e[u][i]) if(!dis[v]) dis[v] = dis[u] + 1, q.push(v);
	}
	vis[1] = true;
	dfs ( vi{1} );
	L(i, 2, n) cout << D[i] << '\n';
	return 0;
}