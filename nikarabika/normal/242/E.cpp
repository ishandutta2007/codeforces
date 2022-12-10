#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69, maxl = 25;
int seg[maxl][maxn * 4], laz[maxn * 4];
int n, m, a[maxn];

void make(int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		for(int i = 0; i < maxl; i++)
			seg[i][id] = bool(a[L] & (1 << i));
		return;
	}
	int mid = (L + R) >> 1;
	make(L, mid, id * 2 + 0);
	make(mid, R, id * 2 + 1);
	for(int i = 0; i < maxl; i++)
		seg[i][id] = seg[i][id * 2 + 0] + seg[i][id * 2 + 1];
}

void update(int x, int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R){
		for(int i = 0; i < maxl; i++)
			if(x & (1 << i))
				seg[i][id] = (R - L) - seg[i][id];
		laz[id] ^= x;
		return;
	}
	int mid = (L + R) >> 1;
	update(laz[id], L, mid, L, mid, id * 2 + 0);
	update(laz[id], mid, R, mid, R, id * 2 + 1);
	laz[id] = 0;
	if(l < mid)
		update(x, l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		update(x, max(l, mid), r, mid, R, id * 2 + 1);
	for(int i = 0; i < maxl; i++)
		seg[i][id] = seg[i][id * 2 + 0] + seg[i][id * 2 + 1];
}

LL get(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R){
		LL ret = 0;
		for(int i = maxl - 1; i >= 0; i--)
			ret = ret * 2 + seg[i][id];
		return ret;
	}
	int mid = (L + R) >> 1;
	update(laz[id], L, mid, L, mid, id * 2 + 0);
	update(laz[id], mid, R, mid, R, id * 2 + 1);
	laz[id] = 0;
	LL ret = 0;
	if(l < mid)
		ret += get(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		ret += get(max(l, mid), r, mid, R, id * 2 + 1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	make();
	cin >> m;
	for(int i = 0; i < m; i++){
		int tp;
		cin >> tp;
		if(tp == 1){
			int fi, se;
			cin >> fi >> se;
			cout << get(fi - 1, se) << '\n';
		}
		else{
			int fi, se, x;
			cin >> fi >> se >> x;
			update(x, fi - 1, se);
		}
	}
	return 0;
}