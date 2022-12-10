//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
int h[maxn], pos[maxn];
vector<int> adj[maxn];
int cnt, n, m;

struct segment_tree{
	LL *seg;
	int sz;
	void set_size(int val){
		sz = val;
		seg = new LL[val * 4];
		for(int i = 0; i < val * 4; i++)
			seg[i] = 0;
		return;
	}
	void add(LL val, int st, int en, int l, int r, int id){
		//cout << "NEGAR" << endl;
		if(r <= st or en <= l)
			return;
		if(st <= l and r <= en){
			//cout << l << ' ' << r << endl;
			seg[id] += val;
			return;
		}
		int mid = (l + r) >> 1;
		add(val, st, en, l, mid, id * 2 + 0);
		add(val, st, en, mid, r, id * 2 + 1);
		return;
	}
	LL get(int idx, int l, int r, int id){
		if(idx < l or r <= idx)
			return 0;
		if(r - l == 1)
			return seg[id];
		int mid = (l + r) >> 1;
		return seg[id] + get(idx, l, mid, id * 2 + 0) + get(idx, mid, r, id * 2 + 1);
	}
} seg[maxn], sor;

int dfs(int v, int p){
	pos[v] = cnt;
	for(auto u : adj[v])
		if(u != p){
			h[u] = h[v] + 1;
			return dfs(u, v);
		}
	return h[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	cnt = 0;
	sor.set_size(n);
	for(auto v : adj[1]){
		h[v] = 1;
		seg[cnt].set_size(dfs(v, 1));
		cnt++;
	}
	for(int i = 0; i < m; i++){
		int ty;
		//cout << "enter:" << endl;
		cin >> ty;
		if(ty){
			int fi;
			cin >> fi;
			if(fi == 1)
				cout << sor.get(0, 0, sor.sz, 1) << '\n';
			else
				cout << seg[pos[fi]].get(h[fi] - 1, 0, seg[pos[fi]].sz, 1) + sor.get(h[fi], 0, sor.sz, 1) << '\n';
		}
		else{
			int fi, se, th;
			cin >> fi >> se >> th;
			if(fi == 1)
				sor.add(se, 0, th + 1, 0, sor.sz, 1);
			else{
				if(th >= h[fi]){
					//cout << "sor: " << 0 << ", " << th - h[fi] + 1 << " and " << sor.sz << endl;
					sor.add(se, 0, th - h[fi] + 1, 0, sor.sz, 1);
				}
				//cout << "other:" << endl;
				if(th > h[fi])
					seg[pos[fi]].add(se, th - h[fi], h[fi] + th, 0, seg[pos[fi]].sz, 1);
				else
					seg[pos[fi]].add(se, h[fi] - th - 1, h[fi] + th, 0, seg[pos[fi]].sz, 1);
			}
		}
	}
	return 0;
}