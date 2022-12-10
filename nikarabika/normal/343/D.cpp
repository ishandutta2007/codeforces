//In the name of "God"
//GOOSHKesha :D
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 5e5 + 85 - 69;
bool seg[maxn * 4], laz[maxn * 4];
int n, q, vis, par[maxn];
vector<int> v[maxn];
pie p[maxn];

void dfs(int x, int pp = -1){
	par[x] = pp;
	p[x].L = vis++;
	for(auto y : v[x])
		if(y != pp)
			dfs(y, x);
	p[x].R = vis;
}

void set1(int l, int r, int L = 0, int R = vis, int id = 1){
	if(l == L and r == R){
		seg[id] = 1;
		laz[id] = 1;
		return;
	}
	int mid = (L + R) >> 1;
	if(laz[id]){
		set1(L, mid, L, mid, id * 2 + 0);
		set1(mid, R, mid, R, id * 2 + 1);
		laz[id] = 0;
	}
	else{
		if(l < mid)
			set1(l, min(mid, r), L, mid, id * 2 + 0);
		if(r > mid)
			set1(max(l, mid), r, mid, R, id * 2 + 1);
		seg[id] = seg[id * 2 + 0] and seg[id * 2 + 1];
	}
}

void set0(int idx, int L = 0, int R = vis, int id = 1){
	seg[id] = 0;
	if(R - L == 1)
		return;
	int mid = (L + R) >> 1;
	if(laz[id]){
		set1(L, mid, L, mid, id * 2 + 0);
		set1(mid, R, mid, R, id * 2 + 1);
		laz[id] = 0;
	}
	if(idx < mid)
		set0(idx, L, mid, id * 2 + 0);
	else
		set0(idx, mid, R, id * 2 + 1);
}

bool get(int l, int r, int L = 0, int R = vis, int id = 1){
	if(l == L and r == R)
		return seg[id];
	int mid = (L + R) >> 1;
	if(laz[id]){
		set1(L, mid, L, mid, id * 2 + 0);
		set1(mid, R, mid, R, id * 2 + 1);
		laz[id] = 0;
	}
	bool ret = 1;
	if(l < mid)
		ret = ret and get(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		ret = ret and get(max(l, mid), r, mid, R, id * 2 + 1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	dfs(1);
	cin >> q;
	while(q--){
		int c, x;
		cin >> c >> x;
		if(c == 1){
			bool farzande_nakhalaf = get(p[x].L, p[x].R);
			set1(p[x].L, p[x].R);
			if(par[x] != -1 and !farzande_nakhalaf)
				set0(p[par[x]].L);
		}
		else if(c == 2)
			set0(p[x].L);
		else
			cout << get(p[x].L, p[x].R) << '\n';
	}
	return 0;
}