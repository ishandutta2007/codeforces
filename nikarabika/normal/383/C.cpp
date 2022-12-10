//sobskdrbhvk
#include <bits/stdc++.h>

//man am A _____ & a pair of Iz wayTn' 230u :)

using namespace std;

#define PB push_back
#define endl '\n'

const int maxn = 2e5 + 85 - 69;
int t, n, m;
int sttime[maxn], fitime[maxn], h[maxn], seg[maxn * 4], val[maxn];
vector<int> adj[maxn];

void dfs(int v, int p = -1){
	sttime[v] = t++;
	for(auto u : adj[v])
		if(u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	fitime[v] = t;
	return;
}

void add(int val, int st, int en, int l = 0, int r = t, int id = 1){
	if(st >= r or en <= l)
		return;
	if(l >= st and r <= en){
		seg[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	return;
}

int get(int idx, int l = 0, int r = t, int id = 1){
	if(idx < l or idx >= r)
		return 0;
	if(r - l == 1)
		return seg[id];
	int mid = (l + r) >> 1;
	return seg[id]
		+ get(idx, l, mid, id * 2 + 0)
		+ get(idx, mid, r, id * 2 + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(h[i] & 1)
			add(-val[i], sttime[i], sttime[i] + 1);
		else
			add(val[i], sttime[i], sttime[i] + 1);
	}
	while(m--){
		int ty;
		cin >> ty;
		if(ty == 1){
			int fi, se;
			cin >> fi >> se;
			if(h[fi] & 1)
				add(-se, sttime[fi], fitime[fi]);
			else
				add(se, sttime[fi], fitime[fi]);
		}
		else{
			int fi;
			cin >> fi;
			if(h[fi] & 1)
				cout << -get(sttime[fi]) << endl;
			else
				cout << get(sttime[fi]) << endl;
		}
	}
	return 0;
}