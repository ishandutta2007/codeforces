#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, M = (1 << 19), inf = 1e9;
int n, m, q, c[2], v;
int a[2][N];
int ck(int o, int x, int l, int r) {
	if(x < 1 || x > c[o]) return inf;
	return abs(l - a[o][x]) + abs(r - a[o][x]);
}
int get(int o, int l, int r) {
	int u1 = lower_bound(a[o] + 1, a[o] + c[o] + 1, l) - a[o];
	int u2 = lower_bound(a[o] + 1, a[o] + c[o] + 1, r) - a[o];
	return min(min(ck(o, u1, l, r), ck(o, u1 - 1, l, r)), min(ck(o, u2, l, r), ck(o, u2 - 1, l, r)));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> c[0] >> c[1] >> v;
	L(t, 0, 1) {
		L(i, 1, c[t]) cin >> a[t][i];
		sort(a[t] + 1, a[t] + c[t] + 1);
	}
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2, d, ns = inf;
		cin >> x1 >> y1 >> x2 >> y2;
		d = abs(x1 - x2);
		if(d == 0) ns = abs(y1 - y2); 
		if(c[1]) ns = min(ns, get(1, y1, y2) + (d + v - 1) / v);
		if(c[0]) ns = min(ns, get(0, y1, y2) + d);
		cout << ns << "\n";
	}
	return 0;
}