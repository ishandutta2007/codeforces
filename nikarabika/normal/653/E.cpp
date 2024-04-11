#include <bits/stdc++.h>

using namespace std;

#undef next
#define next Next
#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 5e5 + 85 - 69;
vector<int> adj[maxn], vert[maxn];
int next[maxn], comp;
int n, m;

int root(int v){return (next[v] == v) ? v : next[v] = root(next[v]);}

void dfs(int v){
	vert[comp].PB(v);
	next[v] = v + 1;
	int p = 0;
	for(int u = root(1); u <= n; u = root(u + 1)){
		while(p < sz(adj[v]) and adj[v][p] < u) p++;
		if(p != sz(adj[v]) and adj[v][p] == u)
			continue;
		dfs(u);
	}
	return;
}

int main(){
	for(int i = 0; i < maxn; i++)
		next[i] = i;
	int kkk;
	scanf("%d%d%d", &n, &m, &kkk);
	for(int i = 0; i < m; i++){
		int fi, se;
		scanf("%d%d", &fi, &se);
		fi--, se--;
		if(se) adj[fi].PB(se);
		if(fi) adj[se].PB(fi);
	}
	n--;
	for(int i = 0; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	for(int i = 1; i <= n; i++)
		if(next[i] == i)
			dfs(i), comp++;
	int cntto = 0;
	for(int i = 0; i < comp; i++){
		int cntman = 0;
		for(auto v : vert[i]){
			int id = lower_bound(adj[0].begin(), adj[0].end(), v) - adj[0].begin();
			if(id != sz(adj[0]) and adj[0][id] == v)
				cntman++;
		}
		if(cntman == sz(vert[i])){
			cout << "impossible" << endl;
			return 0;
		}
		else cntto++;
	}
	if(sz(adj[0]) + kkk > n){
		cout << "impossible" << endl;
		return 0;
	}
	if(cntto > kkk)
		cout << "impossible" << endl;
	else
		cout << "possible" << endl;
	return 0;
}