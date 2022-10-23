#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 207;
int n, c[N][N], mid[N][N], fa[N];
ll qwq[N][N];
ll f[N][N];
int solve(int l, int r) {
	if(l > r) return 0;
	int p = mid[l][r];
	int ls = solve(l, p - 1);
	int rs = solve(p + 1, r);
	fa[ls] = fa[rs] = p;
	return p;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		L(j, 1, n) {
			cin >> c[i][j];
		}
	}
	L(d, 2, n) for(int l = 1, r = d; r <= n; ++l, ++r) 
		qwq[l][r] = qwq[l + 1][r] + qwq[l][r - 1] - qwq[l + 1][r - 1] + c[l][r];
	me(f, 0x3f);
	L(i, 1, n + 1) f[i][i - 1] = 0;
	L(d, 1, n) 
		for(int l = 1, r = d; r <= n; ++l, ++r) {
			L(x, l, r) 
				if(f[l][x - 1] + f[x + 1][r] < f[l][r]) 
					f[l][r] = f[l][x - 1] + f[x + 1][r], mid[l][r] = x;
			f[l][r] += qwq[1][r] - qwq[1][l - 1] - qwq[l][r];
			f[l][r] += qwq[l][n] - qwq[r + 1][n] - qwq[l][r];
		}
	solve(1, n); 
	L(i, 1, n) cout << fa[i] << ' ';
	cout << '\n';
	return 0;
}