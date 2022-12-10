#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 85 - 75;
int T[maxn * 4], a[maxn], b[maxn], x[maxn], y[maxn], k[maxn];
int n, m, q;

void change(int l, int r, int L = 1, int R = n + 1, int id = 1){
	if(l == L and r == R){
		T[id] = q;
		return;
	}
	int mid = (L + R) >> 1;
	if(l < mid)
		change(l, min(mid, r), L, mid, id * 2 + 0);
	if(r > mid)
		change(max(l, mid), r, mid, R, id * 2 + 1);
}

int get(int idx, int L = 1, int R = n + 1, int id = 1){
	if(R - L == 1)
		return T[id];
	int mid = (L + R) >> 1;
	if(idx < mid)
		return max(T[id], get(idx, L, mid, id * 2 + 0));
	return max(T[id], get(idx, mid, R, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(q = 1; q <= m; q++){
		int tp;
		cin >> tp;
		if(tp == 1){
			cin >> x[q] >> y[q] >> k[q];
			change(y[q], y[q] + k[q]);
		}
		else{
			cin >> x[q];
			int id = get(x[q]);
			if(id == 0)
				cout << b[x[q]] << '\n';
			else
				cout << a[x[id] - y[id] + x[q]] << '\n';
		}
	}
	return 0;
}