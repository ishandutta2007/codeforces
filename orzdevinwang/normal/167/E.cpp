#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 607;
int mod;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int f[N][N];
int det(int n) {
	bool flag = 0; int ans = 1;
	L(i, 1, n) {
		int now = 0;
		L(j, i, n) if(f[j][i]) {
				now = j;
				break;
			}
		if(!now) return 0;
		if(now != i) {
			flag ^= 1;
			L(k, i, n) swap(f[i][k], f[now][k]);
		}
		int qwq = ny(f[i][i]);
		L(j, i + 1, n) {
			int t = 1ll * f[j][i] * qwq % mod;
			L(k, i, n) (f[j][k] += mod - 1ll * f[i][k] * t % mod) %= mod;
		}
		ans = 1ll * ans * f[i][i] % mod;
	}
	if(flag) ans = mod - ans;
	return ans;
}
int n, m, ans[N][N], In[N], Out[N], dya[N], dyb[N], cnta, cntb;
int to[N][N]; bool vis[N];
void DFS(int x) {
	if(vis[x]) return;
	vis[x] = 1;
	if(Out[x] == 0) return ans[x][x] = 1, void(); 
	L(i, 1, n) if(to[x][i]) {
		DFS(i);
		L(j, 1, n) (ans[x][j] += 1ll * to[x][i] * ans[i][j] % mod) %= mod;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &mod);
	L(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		to[u][v] ++, Out[u] ++, In[v] ++;
	}
	L(i, 1, n) DFS(i);
	L(i, 1, n) if(In[i] == 0) dya[i] = ++cnta; 
	L(i, 1, n) if(Out[i] == 0) dyb[i] = ++cntb;
	L(i, 1, n) if(In[i] == 0) L(j, 1, n) if(Out[j] == 0) f[dya[i]][dyb[j]] = ans[i][j];
	// L(i, 1, cnta) L(j, 1, cntb) printf("%d%s", f[i][j], j == cntb ? "\n" : " ");
	printf("%d\n", det(cnta));
	return 0;
}