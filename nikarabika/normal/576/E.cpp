//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 5e5 + 85 - 69,
	  maxk = 50;
int sz[maxk][maxn],
	par[maxk][maxn],
	parwei[maxk][maxn],
	col[maxn],
	a[maxn], b[maxn],
	q1[maxn], q2[maxn],
	n, m, k, q;
vector<int> vec[maxn * 4];
vector<pii> hist;
set<pii> s;

pii root(int v, int c){
	if(par[c][v] == v) return {v, 0};
	pii ret = root(par[c][v], c);
	return {ret.L, ret.R xor parwei[c][v]};
}

void dsuadd(int eid){
	int c = col[eid];
	if(c == -1){
		hist.PB({-1, -1});
		return;
	}
	pii vv = root(a[eid], c),
		uu = root(b[eid], c);
	if(vv.L == uu.L){
		hist.PB({-1, -1});
		return;
	}
	if(sz[c][vv.L] < sz[c][uu.L]) swap(vv, uu);
	sz[c][vv.L] += sz[c][uu.L];
	par[c][uu.L] = vv.L;
	parwei[c][uu.L] = !(uu.R xor vv.R);
	hist.PB(MP(uu.L, c));
	return;
}

void undo(void){
	int u = hist.back().L,
		c = hist.back().R;
	hist.pop_back();
	if(u == -1)
		return;
	int v = par[c][u];
	par[c][u] = u;
	sz[c][v] -= sz[c][u];
	return;
}

void undo(int tu){while(tu--)undo();}

bool canadd(int eid, int c){
	pii vv = root(a[eid], c),
		uu = root(b[eid], c);
	if(vv.L == uu.L)
		return vv.R != uu.R;
	return true;
}

void add(int val, int st, int en, int l = 0, int r = q, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		vec[id].PB(val);
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	return;
}

void build(int l = 0, int r = q, int id = 1){
	for(auto x : vec[id])
		dsuadd(x);
	if(r - l <= 1){
		if(canadd(q1[l], q2[l])){
			cout << "YES\n";
			col[q1[l]] = q2[l];
		}
		else
			cout << "NO\n";
		undo(sz(vec[id]));
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	undo(sz(vec[id]));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> q;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < n; j++)
			par[i][j] = j, sz[i][j] = 1;
	for(int i = 0; i < m; i++)
		cin >> a[i] >> b[i], a[i]--, b[i]--;
	memset(col, -1, sizeof col);
	for(int i = 0; i < q; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		q1[i] = fi, q2[i] = se;
		if(~col[fi]){
			auto it = s.lower_bound(MP(fi, -1));
			add(fi, it->R + 1, i);
			s.erase(it);
		}
		s.insert(MP(fi, i));
		col[fi] = se;
	}
	for(auto Pr : s)
		add(Pr.L, Pr.R + 1, q);
	memset(col, -1, sizeof col);
	build();
	return 0;
}