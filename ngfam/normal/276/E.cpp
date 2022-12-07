#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, q, fr[N], chain[N], depth[N], start[N], finish[N], nChain, cur;

vector < int > adj[N];

struct fenwick{
	int bit[N];

	void upd(int i, int val){
		for(; i < N; i += i & -i){
			bit[i] += val;
		}
	}

	int ask(int i){
		int result = 0;
		for(; i > 0; i &= i - 1){
			result += bit[i];
		}
		return result;
	}
}fwt, root;

void dfs(int u){
	fr[u] = ++cur;
	if(u != 1){
		finish[chain[u]] = max(finish[chain[u]], fr[u]);
	}
	else{
		depth[u] = 1;
	}

	for(auto v : adj[u]){
		if(fr[v] != 0) continue;
		
		depth[v] = depth[u] + 1;
		if(u == 1){
			chain[v] = ++nChain;
		}
		else{
			chain[v] = chain[u];
		}
		dfs(v);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("sol.inp", "r", stdin);
		freopen("sol.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &q);

	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

//	int x = 2;

//	cout << chain[x] << " " << finish[chain[x]] << " " << fr[x] << endl;

//	return 0;
	
	while(q--){
		int type; scanf("%d", &type);
		if(type == 1){
			int ver; scanf("%d", &ver);
			printf("%d\n", fwt.ask(fr[ver]) + root.ask(depth[ver]));	
		}
		else{
			int ver, x, d;
			scanf("%d%d%d", &ver, &x, &d);

	//		cout << ver << " " << x << " " << d << endl;

			if(ver == 1){
				root.upd(1, x);
				root.upd(d + 2, -x);
				continue;
			}

			int foo = max(fr[ver] - depth[ver] + 2, fr[ver] - d);
			int koo = min(finish[chain[ver]], fr[ver] + d);

		//	cout << ver << " " << d << " " << koo << endl;

			if(d + 1 >= depth[ver]){
				int shift = d - (depth[ver] - 1) + 1;
			//	cout << ver << " " << d << " " << shift << " " << depth[ver] << endl;
				root.upd(1, x);
				root.upd(shift + 1, -x);
				foo = min(koo + 1, fr[ver] - depth[ver] + shift + 1);
			}
	
		//	cout << ver << " " << d << " " << foo << " " << koo << endl;

			fwt.upd(foo, x);
			fwt.upd(koo + 1, -x);
		}
	}

	return 0;
}