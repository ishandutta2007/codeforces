#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int jc[N], njc[N];
int C(int x, int y) { if(x < 0 || y < 0 || x < y) return 0; return 1ll * jc[x] * njc[y] % mod * njc[x - y] % mod; }
struct WORKER {
	int cnt, t, ans = 1;
	//  \sum\limits_{i = 0}^{t} C_{cnt}^{i}
	void cntup() { ans = (ans << 1) % mod, (ans += mod - C(cnt, t)) %= mod, ++cnt; if(cnt == 0) ans = (t >= 0); }
	void cntdown() { if(cnt == 0) ans = 0; --cnt, (ans += C(cnt, t)) %= mod, ans = 1ll * ans * inv2 % mod; }
	void tup() { (ans += C(cnt, t + 1)) %= mod, ++ t; }
	void tdown() { (ans += mod - C(cnt, t)) %= mod, -- t; }
} a, b, c, d;
int n, m, t, cnt, ans;
char s[N];
int getans() {
	int res = 0;
	if(cnt == 1) {
		L(i, 0, cnt) if((t + i) % 2 == 0) (res += 1ll * abs(t - i) * C(cnt, i) % mod) %= mod;
		res = 1ll * res * inv2 % mod;
		return res;
	}
	(res += 2ll * (t + mod) % mod * a.ans % mod) %= mod;
	(res += mod - 2ll * cnt * b.ans % mod) %= mod;
	(res += 1ll * cnt * c.ans % mod) %= mod;
	(res += mod - 1ll * (t + mod) % mod * d.ans % mod) %= mod;
	res = 1ll * res * qpow(inv2, cnt) % mod;
	return res;
}
void tup() { a.tup(), b.tup(), t++; }
void tdown() { a.tdown(), b.tdown(), t--; }
void cntup() { a.cntup(), b.cntup(), c.cntup(), d.cntup(), c.tup(), d.tup(), cnt++; }
void cntdown() { a.cntdown(), b.cntdown(), c.cntdown(), d.cntdown(), c.tdown(), d.tdown(), cnt--; }
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	jc[0] = njc[0] = 1;
	L(i, 1, n) jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = ny(jc[i]);
	a.cntdown(), b.cntdown(), c.cntdown(), d.cntdown(), b.cntdown(), c.cntdown(), b.tdown(), c.tdown();
	L(i, 1, n) {
		if(s[i] == 'b') {
			if(i % 2) tdown();
			else tup();
		}
		else if(s[i] == '?') {
			cntup();
			if(i % 2 == 0) tup();
		}
	}
	printf("%d\n", getans());
	while(m--) {
		int x; char opt[5]; scanf("%d%s", &x, opt + 1);
		if(opt[1] == 'b') {
			if(x % 2) tdown();
			else tup();
		}
		else if(opt[1] == '?') {
			cntup();
			if(x % 2 == 0) tup();
		}
		if(s[x] == 'b') {
			if(x % 2) tup();
			else tdown();
		}
		else if(s[x] == '?') {
			cntdown();
			if(x % 2 == 0) tdown();
		}
		s[x] = opt[1];
		printf("%d\n", getans());
	}
	return 0;
}