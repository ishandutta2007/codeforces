//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69;
set<pii, greater<pii> > s[maxn];
vector<int> all;
int seg[maxn * 4];
int h[maxn], par[maxn];
pair<pii, pii> po[maxn];
queue<int> Q;
int n;

void build(int l = 0, int r = sz(all), int id = 1){
	if(r - l == 1){
		seg[id] = s[l].begin()->L;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

void modify(int idx, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg[id] = (sz(s[l]) ? s[l].begin()->L : -1);
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, l, mid, id * 2 + 0);
	modify(idx, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]);
	return;
}

int get(int idx, int l = 0, int r = sz(all), int id = 1){
	if(r <= idx)
		return -1;
	if(idx <= l)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(idx, l, mid, id * 2 + 0),
			get(idx, mid, r, id * 2 + 1));
}

int idof(int val){return lower_bound(all.begin(), all.end(), val) - all.begin();}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(h, -1, sizeof h);
	cin >> n;
	n++;
	all.PB(po[0].R.L);
	for(int i = 1; i < n; i++){
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		po[i].L.L = x;
		po[i].L.R = y;
		po[i].R.L = xx;
		po[i].R.R = yy;
		all.PB(po[i].R.L);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n - 1; i++)
		s[idof(po[i].R.L)].insert(MP(po[i].R.R, i));
	build();
	
	//bfs :p
	Q.push(n - 1);
	h[n - 1] = 0;
	while(Q.size() and Q.front()){
		int v = Q.front();
		Q.pop();
		int id = idof(po[v].L.L);
		while(get(id) >= po[v].L.R){
			int lo = id, hi = sz(all);
			while(hi - lo > 1){
				int mid = (lo + hi) >> 1;
				get(mid) >= po[v].L.R ? lo = mid : hi = mid;
			}
			while(sz(s[lo]) and s[lo].begin()->L >= po[v].L.R){
				int u = s[lo].begin()->R;
				s[lo].erase(s[lo].begin());
				Q.push(u);
				h[u] = h[v] + 1;
				par[u] = v;
			}
			modify(lo);
		}
	}
	if(h[0] == -1){
		cout << -1 << endl;
		return 0;
	}
	cout << h[0] << endl;
	int v = 0;
	do{
		cout << (v = par[v]) << ' '; 
	}while(v != n - 1);
	cout << endl;
	return 0;
}