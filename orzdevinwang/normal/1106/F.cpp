#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 209;
const int mod = 998244353;
const int pmod = mod - 1;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int n, m, k;
struct Martix {
	int G[N][N];
	void clear() { L(i, 1, m) L(j, 1, m) G[i][j] = 0; }
	void start() { clear(); L(i, 1, m) G[i][i] = 1; }
} P;
Martix operator * (Martix aa, Martix bb) {
	Martix res; res.clear();
	L(i, 1, m) L(j, 1, m) L(k, 1, m) (res.G[i][j] += 1ll * aa.G[i][k] * bb.G[k][j] % pmod) %= pmod;
	return res;
}
Martix operator ^ (Martix aa, int bb)  {
	Martix res; res.start();
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
map<int, int> mp;
int BSGS(int x, int y) {
	int B = sqrt(mod) + 1, now = y, res = 1, Pow = qpow(x, B); 
	mp[now] = 0;
	L(i, 1, B - 1) now = 1ll * now * x % mod, mp[now] = i;
	L(i, 1, B) {
		res = 1ll * res * Pow % mod;
		if(mp[res]) return i * B - mp[res];
	}
	return -1;
}
void exgcd(int a, int b, ll &x, ll &y) {
	if(b == 0) return x = 1, void();
	exgcd(b, a % b, y, x); y -= (a / b) * x;
	ll tt = x / b;
	x -= tt * b, y += tt * a; 
}
int NY(int a, int Mod) { ll x, y; exgcd(a, Mod, x, y); return (x % Mod + Mod) % Mod; }
int main() {
	scanf("%d", &m);
	L(i, 1, m) scanf("%d", &P.G[m - i + 1][m]);
	L(i, 2, m) P.G[i][i - 1] = 1;
	scanf("%d%d", &n, &k);
	if(k == 1) return puts("1"), 0;
	int cs = (P ^ (n - m)).G[m][m];
	int YG = BSGS(3, k);
	if(YG == -1) return puts("-1"), 0;
	int mm = gcd(YG, cs);
	YG /= mm, cs /= mm;
	if(gcd(mod - 1, cs) != 1) return puts("-1"), 0;
	printf("%d\n", qpow(3, 1ll * YG * NY(cs, mod - 1) % (mod - 1)));
	// printf("%d\n", qpow(pp, cs));
	return 0;
}