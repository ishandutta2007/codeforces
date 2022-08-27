#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
int qpow(int x, int y) {
	if(x == 0) return 0;
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
ll T;
int n, t[N], tpow[N], jc[N], njc[N], ans, wz = -1, now;
int C(int x, int y) { return 1ll * jc[x] * njc[y] % mod * njc[x - y] % mod; }
int main() {
	scanf("%d%lld", &n, &T);
	tpow[0] = jc[0] = njc[0] = 1;
	L(i, 1, n) tpow[i] = 2 * tpow[i - 1] % mod;
	L(i, 1, n) jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = ny(jc[i]); 
	L(i, 1, n) scanf("%d", &t[i]);
	L(i, 1, n) {
		T -= t[i];
		if(T < 0) break;
		else if(T > i) ans++;
		else {
            if(wz == -1) wz = i, now = tpow[i];
            else now = (now * 2 % mod + mod - C(i - 1, wz)) % mod;
            while(wz != T) (now += mod - C(i, wz)) %= mod, wz--; 
			(ans += 1ll * now * ny(qpow(2, i)) % mod) %= mod;
		}
	}
	printf("%d\n", ans);
    return 0;
}