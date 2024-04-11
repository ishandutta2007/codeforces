#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 507;
int n, m;
struct Matrix { bool vis[N][N]; };
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res;
	bitset<N> ts[N], gs[N];
	L(i, 1, n) L(j, 1, n) ts[i][j] = aa.vis[i][j], gs[j][i] = bb.vis[i][j];
	L(i, 1, n) L(j, 1, n) res.vis[i][j] = (ts[i] & gs[j]).any();
	return res;
}
Matrix bz[2][61], now; bool flag = 0;
ll dp[2][61][N], ans;
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		if(val) bz[1][0].vis[u][v] = 1;
		else bz[0][0].vis[u][v] = 1;
	}
	L(i, 1, 60) bz[0][i] = bz[0][i - 1] * bz[1][i - 1], bz[1][i] = bz[1][i - 1] * bz[0][i - 1];
	L(i, 1, n) now.vis[i][i] = 1;
	R(k, 60, 0) {
		Matrix pp = now * bz[flag][k];
		bool ok = 0;
		L(i, 1, n) L(j, 1, n) ok |= pp.vis[i][j];
		if(ok) ans += (1LL << k), now = pp, flag ^= 1;
	}
	if(ans > 1e18) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}