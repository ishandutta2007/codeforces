#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 12;
const int mod = 1e9 + 7;
int n, m, k, f[N][N], sum[N][N], v[N], las[N], all;
bool vis[N][N][N]; 
int dfs(int x, int y) {
	if(x == n + 1) return 1;
	if(y == m + 1) return dfs(x + 1, 1);
	int res = 0;
	if(f[x][y]) {
		if(y >= las[f[x][y]]) return 0;
		int sav = las[f[x][y]];
		all += y - sav, las[f[x][y]] = y, res = dfs(x, y + 1), all += sav - y, las[f[x][y]] = sav;
		return res;
	}
	int pp = -1;
	L(i, 1, k) if(y < las[i] && vis[x][y][i]) {
		if(!v[i] && pp != -1) {
			(res += pp) %= mod;
			continue;
		}
		int sav = las[i];
		all += y - sav, las[i] = y, v[i] ++;
		if(v[i] == 1) pp = dfs(x, y + 1), (res += pp) %= mod;
		else (res += dfs(x, y + 1)) %= mod;
		all += sav - y, las[i] = sav, v[i] --;
	}
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	if(n + m - 1 > k) return puts("0"), 0;
	L(i, 1, n) L(j, 1, m) L(t, 1, k) vis[i][j][t] = 1;
	L(i, 1, n) L(j, 1, m) {
		scanf("%d", &f[i][j]), v[f[i][j]] ++;
		L(a, 1, i) L(b, 1, j) vis[a][b][f[i][j]] = 0;
	}
	L(i, 1, n) L(j, 1, m) sum[i][j] = m * (n - i) + m - j + 1;
	L(i, 1, k) las[i] = m + 1, all += m;
	printf("%d\n", dfs(1, 1));
	return 0;
}