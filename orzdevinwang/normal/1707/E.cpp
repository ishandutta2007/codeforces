#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e5 + 7;
int n, q;
struct inter {
	int l, r;
	inline inter (int L = 0, int R = 0) { l = L, r = R; }
};
inline inter operator + (inter a, inter b) {
	return inter(min(a.l, b.l), max(a.r, b.r));
}
int lg[N];
int a[N], mx[20][N], mn[20][N];
inter T[20][20][N];
inline inter getk(inter u, int k) {
	int p = lg[u.r - u.l + 1];
	return T[k][p][u.l] + T[k][p][u.r - (1 << p) + 1]; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> q;
	L(i, 1, n) cin >> a[i];
	L(i, 2, n) lg[i] = lg[i >> 1] + 1;
	L(i, 1, n) mn[0][i] = mx[0][i] = a[i];
	L(i, 1, 16) L(j, 1, n - (1 << i) + 1) 
		mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]), 
		mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
	L(i, 0, 16) L(j, 1, n - (1 << i) + 1) T[0][i][j] = inter(mn[i][j], mx[i][j]);
	L(t, 1, 18) L(i, 0, 16) L(j, 1, n - (1 << i) + 1) T[t][i][j] = getk(T[t - 1][i][j], t - 1);
	while(q--) {
		int l, r;
		cin >> l >> r;
		inter qwq(l, r);
		if(qwq.l == 1 && qwq.r == n) {
			cout << 0 << '\n';
			continue;
		}
		inter c = getk(qwq, 18);
		if(c.l != 1 || c.r != n) {
			cout << -1 << '\n';
			continue;
		}
		int ns = 1;
		R(t, 17, 0) {
			inter c = getk(qwq, t);
			if(c.l != 1 || c.r != n) qwq = c, ns += 1 << t;
		}
		cout << ns << '\n';
	}
	return 0;
}