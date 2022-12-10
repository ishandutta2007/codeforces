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
#define all(x) x.begin(),x.end()
#define next Next

const int maxn = 4e5;
LL seg[maxn * 4];
int laz[maxn * 4];
int sttime[maxn], fitime[maxn], col[maxn], c[maxn];
vector<int> adj[maxn];
int n, m, tim;

void dfs(int v, int p = -1){
	col[tim] = c[v];
	sttime[v] = tim++;
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v);
	fitime[v] = tim;
	return;
}

void push(int, int, int);

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id] = 1LL << col[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = seg[id * 2 + 0] | seg[id * 2 + 1];
	return;
}

void modify(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id] = 1LL << val;
		laz[id] = val;
		return;
	}
	if(laz[id] != -1) push(l, r, id);
	int mid = (l + r) >> 1;
	modify(val, st, en, l, mid, id * 2 + 0);
	modify(val, st, en, mid, r, id * 2 + 1);
	seg[id] = seg[id * 2 + 0] | seg[id * 2 + 1];
	return;
}

LL get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0LL;
	if(st <= l and r <= en)
		return seg[id];
	if(laz[id] != -1) push(l, r, id);
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id * 2 + 0) | get(st, en, mid, r, id * 2 + 1);
}

void push(int l, int r, int id){
	int mid = (l + r) >> 1;
	modify(laz[id], l, mid, l, mid, id * 2 + 0);
	modify(laz[id], mid, r, mid, r, id * 2 + 1);
	laz[id] = -1;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(laz, -1, sizeof laz);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> c[i], c[i]--;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	build();
	while(m--){
		int ty, fi, se;
		cin >> ty >> fi;
		fi--;
		if(ty == 1){
			cin >> se;
			se--;
			modify(se, sttime[fi], fitime[fi]);
		}
		else
			cout << __builtin_popcountll(get(sttime[fi], fitime[fi])) << '\n';
	}
	return 0;
}