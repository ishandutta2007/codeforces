#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;
typedef pair<int, pie> piie;

#define PB push_back
#define MP make_pair
#define MT(x, y, z) MP(x, MP(y, z))
#define L first
#define M second.first
#define R second.second
#define sz(x) ((int)(x).size())

const int maxn = 500 + 10;
vector<int> adj[maxn];
vector<int> sadj[2 * maxn * maxn];
int par[2 * maxn * maxn];
bool mark[2 * maxn * maxn];
vector<int> ans[2];
int n, m;
queue<int> Q;

int atob(piie x){
	return x.L * maxn * maxn + x.M * maxn + x.R;
}

piie btoa(int x){
	int a1 = x / (maxn * maxn);
	x %= (maxn * maxn);
	int a2 = x / maxn;
	x %= maxn;
	return MT(a1, a2, x);
}

void bfs(int source){
	Q.push(source);
	mark[source] = true;
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(auto u : sadj[v]){
			if(!mark[u]){
				Q.push(u);
				mark[u] = true;
				par[u] = v;
			}
		}
	}
}

void make(int x){
	while(x != atob(MT(0, 1, n))){
		ans[1].PB(btoa(x).R);
		ans[0].PB(btoa(x).M);
		x = par[par[x]];
	}
	ans[0].PB(1);
	ans[1].PB(n);
	return;
}

inline void print(const vector<int> &v){
	for(int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << ' ';
	cout << '\n';
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi;
		cin >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j)
				for(auto u : adj[i])
					sadj[atob(MT(0, i, j))].PB(atob(MT(1, u, j)));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(auto u : adj[j])
				if(u != i)
					sadj[atob(MT(1, i, j))].PB(atob(MT(0, i, u)));
	bfs(atob(MT(0, 1, n)));
	if(!mark[atob(MT(0, n, 1))]){
		cout << -1 << endl;
		return 0;
	}
	make(atob(MT(0, n, 1)));
	cout << sz(ans[0]) - 1 << '\n';
	print(ans[0]);
	print(ans[1]);
	return 0;
}