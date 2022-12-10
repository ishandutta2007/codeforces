//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define PB push_back

const int maxn = 3e5 + 85 - 69;
const LL Mod = 1000000007;
vector<int> adj[maxn];
LL h[maxn], ssstime[maxn], ffftime[maxn];
int n, q;
int t;

struct fenwick_tree{
	LL fen[maxn];
	fenwick_tree(){
		for(int i = 0; i < maxn; i++)
			fen[i] = 0;
	}
	void add(LL val, int id){
		while(id < maxn){
			fen[id] = (fen[id] + val) % Mod;
			id += id & -id;
		}
		return;
	}
	void add(LL val, int st, int en){
		add(val, st);
		add(-val, en + 1);
		return;
	}
	LL get(int id){
		LL ret = 0;
		while(id > 0){
			ret = (ret + fen[id]) % Mod;
			id -= id & -id;
		}
		return ret;
	}
} fenx, fenk;

void dfs(int v){
	ssstime[v] = ++t;
	for(auto u : adj[v]){
		h[u] = h[v] + 1;
		dfs(u);
	}
	ffftime[v] = t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++){
		int par[i];
		cin >> par[i];
		adj[par[i]].PB(i);
	}
	dfs(1);
	cin >> q;
	while(q--){
		int ty;
		cin >> ty;
		if(ty == 1){
			LL fi, se, th;
			cin >> fi >> se >> th;
			fenx.add((se + h[fi] * th) % Mod, ssstime[fi], ffftime[fi]);
			fenk.add(th, ssstime[fi], ffftime[fi]);
		}
		else{
			int fi;
			cin >> fi;
			LL x = fenx.get(ssstime[fi]);
			LL k = fenk.get(ssstime[fi]);
			cout << (((x - k * h[fi]) % Mod) + Mod) % Mod << '\n';
		}
	}
	return 0;
}