#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 125;
const int mod = 12345;
int maxn = 1;
struct Matrix {
	int f[N][N];
	void Print() { L(i, 0, maxn - 1) L(j, 0, maxn - 1) printf("%3d%s", f[i][j], j == maxn - 1 ? "\n" : " "); }
	void clear() { L(i, 0, maxn - 1) L(j, 0, maxn - 1) f[i][j] = 0; }
	void start() { clear(); L(i, 0, maxn - 1) f[i][i] = 1; }
} G;
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res; res.clear();
	L(i, 0, maxn - 1) L(j, 0, maxn - 1) L(k, 0, maxn - 1) (res.f[i][j] += 1ll * aa.f[i][k] * bb.f[k][j] % mod) %= mod;
	return res;
}
Matrix operator ^ (Matrix aa, ll bb) {
	Matrix res; res.start();
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int m, win[N] /* zz win ! */, Mul[26], flag[26], mp[26][N]; ll n;
vector<int> ve[26];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int lcm(int x, int y) { return 1ll * x * y / gcd(x, y); }
int f[N];
int gethas() { int now = 1, res = 0; L(i, 0, 25) res += now * f[i], now *= Mul[i]; return res; }
void getsz(int x) { L(i, 0, 25) f[i] = x % Mul[i], x /= Mul[i]; }
int getnxt(int x, int y) {
	getsz(x), f[y] ++, f[y] %= Mul[y];
	return gethas();
}
int main() {
	scanf("%lld%d", &n, &m);
	while(m--) {
		char s[5]; int k; scanf("%s%d", s, &k), flag[s[0] - 'A'] = 1;
		ve[s[0] - 'A'].push_back(k);
	}
	L(i, 0, 25) {
		Mul[i] = 1;
		for(int x : ve[i]) Mul[i] = lcm(Mul[i], x);
		for(int x : ve[i]) L(j, 0, Mul[i] / x - 1) mp[i][j * x] = 1;
		maxn *= Mul[i];
	}
	// L(i, 0, maxn - 1) {
	// 	getsz(i);
	// 	cout << i << " : ";
	// 	L(j, 0, 25) if(flag[j]) cout << f[j] << " ";
	// 	puts("");
	// 	cout << "nxt B : " << getnxt(i, 1) << "\n";
	// }
	// cout << maxn << endl;
	L(i, 0, maxn - 1) L(t, 0, 25) if(flag[t]) G.f[i][getnxt(i, t)] ++;
	// G.Print();
	Matrix res = G ^ n; int ans = 0;
	L(i, 0, maxn - 1) {
		getsz(i);
		bool ok = 1;
		L(j, 0, 25) if(flag[j]) ok &= mp[j][f[j]];
		// cout << i << ": " << ok << endl;
		if(ok) (ans += res.f[0][i]) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}