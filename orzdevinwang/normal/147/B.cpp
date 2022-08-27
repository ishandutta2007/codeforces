#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 333;
const int inf = 1e9;
int maxn;
struct Matrix {
	int f[N][N];
	void Print() { L(i, 1, maxn) L(j, 1, maxn) printf("%3d%s", f[i][j], j == maxn ? "\n" : " "); }
} ;
Matrix clear() {
	Matrix res;
	L(i, 1, maxn) L(j, 1, maxn) res.f[i][j] = -inf;
	return res;
}
Matrix start() {
	Matrix res = clear();
	L(i, 1, maxn) res.f[i][i] = 0;
	return res;
}
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res = clear();
	L(i, 1, maxn) L(j, 1, maxn) L(k, 1, maxn) res.f[i][j] = max(res.f[i][j], aa.f[i][k] + bb.f[k][j]);
	return res;
}
int n, m; Matrix f[10];
bool check(Matrix x) {
	L(i, 1, n) if(x.f[i][i] > 0) return 1;
	return 0;
}
int main() {
	scanf("%d%d", &n, &m), maxn = n;
	f[0] = start();
	L(i, 1, m) {
		int u, v, vala, valb;
		scanf("%d%d%d%d", &u, &v, &vala, &valb);
		f[0].f[u][v] = vala;
		f[0].f[v][u] = valb;
	}
	// (f[0]).Print();
	// (start()).Print();
	// (start() * f[0]).Print();
	L(i, 1, 9) f[i] = f[i - 1] * f[i - 1];
	if(!check(f[9])) return puts("0"), 0;
	Matrix now = start(); int ans = 1;
	R(i, 8, 0) {
		Matrix pp = now * f[i];
		if(!check(pp)) now = pp, ans += (1 << i);
	}
	printf("%d\n", ans);
	return 0;
}