//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) (x).begin(),(x).end()
#undef next
#define next NEXT

const int maxn = 3000;
vector<int> adj[maxn], next[maxn];
vector<int> bad[maxn * maxn];
int par[maxn * maxn], h[maxn * maxn];
int n, m, k;
queue<int> Q;

int MP2(int v, int u){
	return v * n + u;
}

void print(int vert){
	if(vert < n){
		cout << 1 << ' ' << vert + 1 << ' ';
		return;
	}
	print(par[vert]);
	cout << vert % n + 1 << ' ';
	return;
}

int Next(int id, int v){return next[id][v] == v ? v : next[id][v] = Next(id, next[id][v]);}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < k; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--, th--;
		bad[MP2(fi, se)].PB(th);
	}
	for(int i = 0; i < n; i++){
		sort(all(adj[i]));
		for(int j = 0; j < sz(adj[i]); j++)
			next[i].PB(j);
		next[i].PB(sz(adj[i]));
		for(int j = 0; j < n; j++)
			sort(all(bad[MP2(i, j)]));
	}
	for(int i = 0; i < sz(adj[0]); i++){
		int v = adj[0][i];
		next[0][i] = i + 1;
		h[v] = 1;
		Q.push(v);
	}
	while(Q.size()){
		int vert = Q.front();
		int v = vert / n, u = vert % n, w;
		Q.pop();
		if(u == n - 1){
			cout << h[vert] << '\n';
			print(vert);
			cout << '\n';
			return 0;
		}
		int ptr = 0;
		for(int i = Next(u, 0); i < sz(adj[u]); i = Next(u, i + 1)){
			w = adj[u][i];
			ptr = lower_bound(all(bad[vert]), w) - bad[vert].begin();
			if(ptr < sz(bad[vert]) and bad[vert][ptr] == w)
				continue;
			int vert2 = MP2(u, w);
			par[vert2] = vert;
			h[vert2] = h[vert] + 1;
			Q.push(vert2);
			next[u][i] = i + 1;
		}
	}
	cout << -1 << '\n';
	return 0;
}