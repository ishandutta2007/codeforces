#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second
#define MP make_pair

typedef pair<int, int> pie;

const int maxn = 1e5 + 10;
int n, w, m;
int a[maxn];
pie t[maxn * 4];
int x[maxn * 4];

void build(int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		t[id] = MP(L, a[L]);
		return;
	}
	int mid = (L + R) >> 1;
	build(L, mid, id * 2 + 0);
	build(mid, R, id * 2 + 1);
	if(t[id * 2 + 0].R < t[id * 2 + 1].R)
		t[id] = t[id * 2 + 0];
	else
		t[id] = t[id * 2 + 1];
}

void update(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R){
		x[id]++;
		t[id].R++;
		return;
	}
	int mid = (L + R) >> 1;
	if(l < mid)
		update(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		update(max(l, mid), r, mid, R, id * 2 + 1);
	int lnum = t[id * 2 + 0].R, lin = t[id * 2 + 0].L;
	int rnum = t[id * 2 + 1].R, rin = t[id * 2 + 1].L;
	if(lnum < rnum){
		t[id].R = lnum + x[id];
		t[id].L = lin;
	}
	else{
		t[id].R = rnum + x[id];
		t[id].L = rin;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> w;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build();
	while(m--){
		int e, b = t[1].L - w + 1;
		b = max(0, b);
		e = b + w;
		update(b, e);
	}
	cout << t[1].R << endl;
	return 0;
}