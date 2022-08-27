#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 20007;
int n, q, a[N], st[N][15], lg[N], ns[N][15][31]; // ns_o,i,j  o  2^i  j  x+a_x 
int Get (int x, int y) {
	return x + a[x] > y + a[y] ? x : y;
}
int qrymx (int l, int r) {
	const int p = lg[r - l + 1];
	return Get (st[l][p], st[r - (1 << p) + 1][p]);
}
int now[31], vuq[31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 2, n) lg[i] = lg[i - 1] + ((i & -i) == i);
	L(i, 1, n) cin >> a[i], a[i] = min(a[i], n - i), st[i][0] = i;
	L(i, 0, 14) L(o, 1, n - (1 << (i - 1))) st[o][i] = Get(st[o][i - 1], st[o + (1 << (i - 1))][i - 1]); 
	L(o, 1, n) L(j, 0, 30) ns[o][0][j] = qrymx (o, min(n, o + a[o] + j));
	L(i, 1, 14) L(o, 1, n) {
		L(r1, 0, 30) ns[o][i][r1] = ns[o][i - 1][r1];
		L(r1, 0, 30) L(r2, 0, 30 - r1) ns[o][i][r1 + r2] = Get(ns[o][i][r1 + r2], ns[ns[o][i - 1][r1]][i - 1][r2]);
	}
	while(q--) {
		int l, r, k, ans = 2;
		cin >> l >> r >> k;
		if(l + a[l] + k >= r) {
			cout << (l == r ? 0 : 1) << '\n';
			continue;
		}
		L(i, 0, k) now[i] = l;
		R(z, 14, 0) {
			L(i, 0, k) vuq[i] = now[i];
			L(r1, 0, k) L(r2, 0, k - r1) vuq[r1 + r2] = Get(vuq[r1 + r2], ns[now[r1]][z][r2]);
			bool ok = true;
			L(i, 0, k) if(vuq[i] + a[vuq[i]] + (k - i) >= r) ok = false;
			if(!ok) continue;
			ans += (1 << z);
			L(i, 0, k) now[i] = vuq[i];	
		}
		cout << ans << '\n';
	}
	return 0;
}