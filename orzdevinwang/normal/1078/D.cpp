#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 6e5 + 7;
int n, r[N], l[N], up[20][N], dw[20][N], lg[N];
struct orz {
	int st[20][N], a[N];
	void init() {
		L(i, 1, n * 3) st[0][i] = i;
		L(i, 1, 19) L(j, 1, n * 3 - (1 << i) + 1) 
			st[i][j] = a[st[i - 1][j]] > a[st[i - 1][j + (1 << (i - 1))]] ? 
			st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
	}
	inline int qry(int l, int r) { 
		if(l > r) assert (0);
		int p = lg[r - l + 1]; 
		return a[st[p][l]] > a[st[p][r - (1 << p) + 1]] ? st[p][l] : st[p][r - (1 << p) + 1]; 
	}
} s1;
struct zro {
	int st[20][N], a[N];
	void init() {
		L(i, 1, n * 3) st[0][i] = i;
		L(i, 1, 19) L(j, 1, n * 3 - (1 << i) + 1) 
			st[i][j] = a[st[i - 1][j]] < a[st[i - 1][j + (1 << (i - 1))]] ? 
			st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
	}
	inline int qry(int l, int r) {
		if(l > r) assert (0); 
		int p = lg[r - l + 1]; 
		return a[st[p][l]] < a[st[p][r - (1 << p) + 1]] ? st[p][l] : st[p][r - (1 << p) + 1]; 
	}
} s2;
int get (int x) {
	int ns = 0, wr = x, wl = x;
	R(i, 19, 0) if(
	max(up[i][s1.qry(wl, wr)], up[i][s2.qry(wl, wr)]) - 
	min(dw[i][s1.qry(wl, wr)], dw[i][s2.qry(wl, wr)]) < n - 1) {
		int cl = wl, cr = wr;
		wr = max(up[i][s1.qry(cl, cr)], up[i][s2.qry(cl, cr)]), 
		wl = min(dw[i][s1.qry(cl, cr)], dw[i][s2.qry(cl, cr)]), 
		ns += 1 << i;
	}
	return ns + 1;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if(n == 1) return cout << 0 << '\n', 0;
//	L(i, 1, n) r[i] = 1;
	L(i, 1, n) cin >> r[i];
	L(i, 1, n) r[i + n] = r[i + n * 2] = r[i];
	L(i, 1, n * 3) l[i] = max(i - r[i], 1), r[i] = min(r[i] + i, 3 * n), s1.a[i] = r[i], s2.a[i] = l[i];
	L(i, 2, n * 3) lg[i] = lg[i >> 1] + 1;
	s1.init(), s2.init();
	L(i, 1, n * 3) up[0][i] = r[i], dw[0][i] = l[i];
	L(i, 1, 19) L(j, 1, n * 3) 
		up[i][j] = max(up[i - 1][s1.qry(dw[i - 1][j], up[i - 1][j])], 
		up[i - 1][s2.qry(dw[i - 1][j], up[i - 1][j])]), 
		
		dw[i][j] = min(dw[i - 1][s1.qry(dw[i - 1][j], up[i - 1][j])], 
		dw[i - 1][s2.qry(dw[i - 1][j], up[i - 1][j])]);
//	cout << dw[1][n + 2] << ' ' << up[1][n + 2] << '\n';
	L(i, 1, n) cout << get(i + n) << ' ';
	return 0; 
}