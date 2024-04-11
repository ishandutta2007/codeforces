#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int ll;

const int maxn = 1e5 + 10;
int T[maxn << 2], Tr[maxn << 2];
int n, q;

void add(int val, int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R){
		T[id] |= val;
		Tr[id] |= val;
		return;
	}
	int mid = (L + R) >> 1;
	add(Tr[id], L, mid, L, mid, id * 2 + 0);
	add(Tr[id], mid, R, mid, R, id * 2 + 1);
	Tr[id] = 0;
	if(l < mid)
		add(val, l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		add(val, max(mid, l), r, mid, R, id * 2 + 1);
	T[id] = T[id * 2 + 0] & T[id * 2 + 1];
}

ll query(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R)
		return T[id];
	int mid = (L + R) >> 1;
	add(Tr[id], L, mid, L, mid, id * 2 + 0);
	add(Tr[id], mid, R, mid, R, id * 2 + 1);
	Tr[id] = 0;
	ll ret = (1LL << 30) - 1;
	if(l < mid)
		ret &= query(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		ret &= query(max(mid, l), r, mid, R, id * 2 + 1);
	return ret;
}

ll ele(int idx, int L = 0, int R = n, int id = 1){
	if(R - L == 1)
		return T[id];
	int mid = (L + R) >> 1;
	add(Tr[id], L, mid, L, mid, id * 2 + 0);
	add(Tr[id], mid, R, mid, R, id * 2 + 1);
	Tr[id] = 0;
	if(idx < mid)
		return ele(idx, L, mid, id * 2 + 0);
	else
		return ele(idx, mid, R, id * 2 + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	vector<pair<pair<int, int>, ll> > v;
	while(q--){
		int fi, se, th;
		cin >> fi >> se >> th;
		add(th, fi - 1, se);
		v.PB(MP(MP(fi - 1, se), th));
	}
	for(int i = 0; i < v.size(); i++){
		int x = query(v[i].L.L, v[i].L.R);
		if(x != v[i].R){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << ele(i) << ' ';
	cout << endl;
	return 0;
}