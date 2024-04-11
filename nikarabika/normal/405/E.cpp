//In the name of "God"
//ino mizanam ta dg enghad nagi graph cutting sakhte :D
//LOOOOOOOL
#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
bool mark[maxn];
int n, m, h[maxn];
vector<int> adj[maxn], bagh[maxn];
set<int> used[maxn];

bool dfs(int v, int p){
	mark[v] = true;
	for(auto u : adj[v]){
		if(u == p)
			continue;
		if(!mark[u]){
			if(dfs(u, v))
				bagh[v].PB(u);
		}
		else if(used[v].find(u) == used[v].end())
			bagh[v].PB(u);
	}
	for(int i = 0; i + 1 < bagh[v].size(); i += 2){
		used[bagh[v][i]].insert(v);
		used[v].insert(bagh[v][i]);
		used[bagh[v][i + 1]].insert(v);
		used[v].insert(bagh[v][i + 1]);
		cout << bagh[v][i] << ' ' << v << ' ' << bagh[v][i + 1] << '\n';
	}
	if(bagh[v].size() & 1){
		used[p].insert(v);
		used[v].insert(p);
		used[bagh[v].back()].insert(v);
		used[v].insert(bagh[v].back());
		cout << p << ' ' << v << ' ' << bagh[v].back() << '\n';
		return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	if(m & 1)
		cout << "No solution" << endl;
	else
		dfs(1, -1);
	return 0;
}