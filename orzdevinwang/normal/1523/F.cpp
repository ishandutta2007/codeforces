#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 15, M = 114, inf = 1e9 + 2e6;
int n, m, ns, xa[N], ya[N], xb[M], yb[M], t[M];
int f[1 << N][M], g[1 << N][M];
int main() {
	memset(f, 0x3f, sizeof(f));
	memset(g, -1, sizeof(g));
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 0, n - 1) cin >> xa[i] >> ya[i];
	L(i, 1, m) cin >> xb[i] >> yb[i] >> t[i];
	L(i, 1, m) L(j, i + 1, m) if(t[i] > t[j]) swap(t[i], t[j]), swap(xb[i], xb[j]), swap(yb[i], yb[j]);
	L(i, 0, n - 1) f[1 << i][0] = 0;
	L(i, 1, m) g[0][i] = 1;
	L(i, 0, (1 << n) - 1) {
		L(j, 1, m) {
			int ret = inf;
			L(k, 0, n - 1) if (i >> k & 1) ret = min(ret, abs(xa[k] - xb[j]) + abs (ya[k] - yb[j]));
			L(k, 0, m - 1) if (ret + f[i][k] <= t[j]) g[i][j] = max(g[i][j], k + 1);
			if(g[i][j] >= 0) {
				f[i][g[i][j]] = min(f[i][g[i][j]], t[j]);
				L(k, j + 1, m) if (t[j] + abs (xb[j] - xb[k]) + abs (yb[j] - yb[k]) <= t[k]) 
				g[i][k] = max(g[i][k], g[i][j] + 1);
			}
		}
		L(j, 1, m) if(g[i][j] >= 0) L(k, 0, n - 1) if(!(i >> k & 1)) 
			f[i | (1 << k)][g[i][j]] = min(f[i | (1 << k)][g[i][j]], abs(xa[k] - xb[j]) + abs (ya[k] - yb[j]) + t[j]); 
		L(j, 0, n - 1) if(!(i >> j & 1)) {
			int ret = inf;
			L(k, 0, n - 1) if (i >> k & 1) ret = min(ret, abs (xa[j] - xa[k]) + abs (ya[j] - ya[k]));
			L(k, 0, m) f[i | (1 << j)][k] = min(f[i | (1 << j)][k], f[i][k] + ret);
		} 
		L(j, 1, m) ns = max(ns, g[i][j]);
		L(j, 1, m) if(f[i][j] < inf) ns = max(ns, j) ;
	}
	cout << ns << "\n";
	return 0;
}