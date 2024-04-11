#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 555;
const int mod = 1e9 + 7, inv2 = (mod + 1) / 2;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
struct Num {
	int x, y;
	Num (int xx = 0, int yy = 0) { x = xx, y = yy; }
	friend Num operator + (Num aa, Num bb) { 
		return Num((aa.x + bb.x) % mod, (aa.y + bb.y) % mod); 
	}
	friend Num operator - (Num aa, Num bb) { 
		return Num((aa.x - bb.x + mod) % mod, (aa.y - bb.y + mod) % mod); 
	}
	friend Num operator * (Num aa, Num bb) { 
		return Num(((ll) aa.x * bb.x % mod + (ll) aa.y * bb.y % mod * 5 % mod) % mod, 
		((ll) aa.x * bb.y % mod + (ll) aa.y * bb.x % mod) % mod); 
	}
	Num Inv() {
		int qwq = qpow(((ll) y * y % mod * 5 % mod + mod - (ll) x * x % mod) % mod);
		return Num((ll) (mod - x) * qwq % mod, (ll) qwq * y % mod);
	}
	friend Num operator / (Num aa, Num bb) {
		return aa * bb.Inv();
	}
	friend Num operator ^ (Num x, ll y) {
		Num res(1, 0);
		for(; y; x = x * x, y >>= 1) if(y & 1) res = res * x; 
		return res;
	}
} ;
int k, S[N][N], fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	S[0][0] = 1;
	L(i, 1, x) L(j, 1, i) S[i][j] = (S[i - 1][j - 1] + (ll) (i - 1) * S[i - 1][j]) % mod; 
} 
int C(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int calc(ll x) {
	Num res(0), tw(1);
	L(i, 0, k) {
		Num now(0);
		L(j, 0, i) {
			Num val = (Num(inv2, inv2) ^ j) * (Num(inv2, mod - inv2) ^ (i - j)), z;
			if(val.x == 1 && val.y == 0) z = Num((x + 1) % mod);
			else z = ((val ^ (x + 3)) - Num(1)) / (val - Num(1)) - val - Num(1);
			z = z * Num(C(i, j));
			if(j & 1) z = Num() - z;
			now = now + z;
		}
		now = now * Num(S[k][i]);
		res = res + now * tw;
		tw = tw / Num(0, 1);
	}
	if(k & 1) res = Num() - res;
	res = res * Num(ifac[k]);
	return res.x;
}
ll l, r;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> k >> l >> r;
	init(202);
	cout << (calc(r) - calc(l - 1) + mod) % mod << "\n";
	return 0;
}