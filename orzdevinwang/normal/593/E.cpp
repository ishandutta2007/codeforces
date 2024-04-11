#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 22;
const int mod = 1e9 + 7;
int maxn;
struct Matrix {
	int f[N][N];
	void clear() { L(i, 1, maxn) L(j, 1, maxn) f[i][j] = 0; }
	void start() { clear(); L(i, 1, maxn) f[i][i] = 1; }
} G, now;
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res; res.clear();
	L(i, 1, maxn) L(j, 1, maxn) L(k, 1, maxn) (res.f[i][j] += 1ll * aa.f[i][k] * bb.f[k][j] % mod) %= mod;
	return res;
}
Matrix operator ^ (Matrix aa, int bb) {
	Matrix res; res.start();
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int n, m, q, f[N][N];
#define P(i, j) (((i) - 1) * m + j)
void upd(int i, int j) {
	G.f[P(i, j)][P(i, j)] = f[i][j];
	if(i > 1) G.f[P(i, j)][P(i - 1, j)] = G.f[P(i - 1, j)][P(i, j)] = (f[i][j] & f[i - 1][j]);
	if(j > 1) G.f[P(i, j)][P(i, j - 1)] = G.f[P(i, j - 1)][P(i, j)] = (f[i][j] & f[i][j - 1]);
	if(i < n) G.f[P(i, j)][P(i + 1, j)] = G.f[P(i + 1, j)][P(i, j)] = (f[i][j] & f[i + 1][j]);
	if(j < m) G.f[P(i, j)][P(i, j + 1)] = G.f[P(i, j + 1)][P(i, j)] = (f[i][j] & f[i][j + 1]);
}
int main() {
	scanf("%d%d%d", &n, &m, &q), maxn = n * m;
	int las = 1;
	L(i, 1, n) L(j, 1, m) f[i][j] = 1;
	L(i, 1, n) L(j, 1, m) upd(i, j);
	now.start();
	while(q--) {
		// cout << "qwq\n";
		int opt, x, y, t;
		scanf("%d%d%d%d", &opt, &x, &y, &t);
		// cout << "qaq\n";
		now = now * (G ^ (t - las));
		// cout << "tat\n";
		// cout << now.f[P(1, 1)][P(1, 1)] << endl;
		if(opt == 1) printf("%d\n", now.f[P(1, 1)][P(x, y)]);
		if(opt == 2) f[x][y] = 0, upd(x, y);
		if(opt == 3) f[x][y] = 1, upd(x, y);
		las = t;
	}
	return 0;
}