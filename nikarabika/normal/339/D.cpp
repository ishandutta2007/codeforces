#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 17) + 10;
int t[maxn * 4];
int n, sz, m;
int a[maxn];

void build(bool h = (n % 2), int L = 0, int R = sz, int id = 1){
	if(R - L == 1){
		t[id] = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(!h, L, mid, id * 2 + 0);
	build(!h, mid, R, id * 2 + 1);
	if(!h)
		t[id] = t[id * 2 + 0] ^ t[id * 2 + 1];
	else
		t[id] = t[id * 2 + 0] | t[id * 2 + 1];
}

void update(int idx, bool h = n & 1, int L = 0, int R = sz, int id = 1){
	if(R - L == 1){
		t[id] = a[L];
		return;
	}
	int mid = (L + R)>>1;
	if(idx < mid)
		update(idx, !h, L, mid, id * 2 + 0);
	else
		update(idx, !h, mid, R, id * 2 + 1);
	if(!h)
		t[id] = t[id * 2 + 0] ^ t[id * 2 + 1];
	else
		t[id] = t[id * 2 + 0] | t[id * 2 + 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	sz = 1 << n;
	for(int i = 0; i < sz; i++)
		cin >> a[i];
	build();
	while(m--){
		int fi, se;
		cin >> fi >> se;
		a[fi - 1] = se;
		update(fi - 1);
		cout << t[1] << endl;
	}
	return 0;
}