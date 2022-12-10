//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
int sttime[maxn], fitime[maxn], ans[maxn], Time;
int seg_cnt[maxn * 4], seg_val[maxn * 4];
vector<int> adj[maxn], vecrem[maxn], vecadd[maxn];
piiii quer[maxn];
int n, m;

void update(int l, int r, int id){
	if(seg_val[id])
		seg_cnt[id] = r - l;
	else if(r - l == 1)
		seg_cnt[id] = 0;
	else
		seg_cnt[id] = seg_cnt[id * 2 + 0] + seg_cnt[id * 2 + 1];
	return;
}

void add(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg_val[id] += val;
		update(l, r, id);
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	update(l, r, id);
	return;
}

void dfs(int v, int p = -1){
	sttime[v] = Time++;
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v);
	fitime[v] = Time;
	return;
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
	dfs(1);
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		quer[i] = {{sttime[fi], fitime[fi]}, {sttime[se], fitime[se]}};
		vecadd[sttime[fi]].PB(i);
		vecrem[fitime[fi]].PB(i);
		vecadd[sttime[se]].PB(i);
		vecrem[fitime[se]].PB(i);
	}
	for(int i = 0; i < n; i++){
		for(auto id : vecadd[i]){
			add(+1, quer[id].L.L, quer[id].L.R);
			add(+1, quer[id].R.L, quer[id].R.R);
		}
		for(auto id : vecrem[i]){
			add(-1, quer[id].L.L, quer[id].L.R);
			add(-1, quer[id].R.L, quer[id].R.R);
		}
		ans[i] = seg_cnt[1];
	}
	for(int i = 1; i <= n; i++)
		cout << max(0, ans[sttime[i]] - 1) << ' ';
	cout << '\n';
	return 0;
}