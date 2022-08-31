#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 3e5 + 7;
const int mod = 1019260817;
const int G = 19491001;
const int iG = 972668243;
template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
	x *= f;
}
template<typename T> inline void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int n, m, a[N], vis[N];
int Pow[N], iPow[N];
struct fenwick {
	int mx, sz[N];
	void cle() {
		L(i, 1, mx) sz[i] = 0;
	}
	void add(int wz, int val) {
		for(; wz <= mx; wz += (wz & -wz)) (sz[wz] += val) %= mod;
	}
	int pre(int wz) {
		int res = 0;
		for(; wz; wz -= (wz & -wz)) (res += sz[wz]) %= mod;
		return res;
	}
	int qry(int l, int r) {
		return (pre(r) - pre(l - 1) + mod) % mod;
	}
} s1, s2;
void init(int mx) {
	Pow[0] = iPow[0] = 1;
	L(i, 1, mx) Pow[i] = (ll) Pow[i - 1] * G % mod, iPow[i] = (ll) iPow[i - 1] * iG % mod;
}
void Main() {
	read(n), init(n), s1.mx = s2.mx = n, s1.cle(), s2.cle();
	L(i, 1, n) read(a[i]);
	L(i, 1, n) {
		int len = min(a[i] - 1, n - a[i]);
		if((ll) s1.qry(a[i] - len, a[i]) * Pow[a[i]] % mod != (ll) s2.qry(a[i], a[i] + len) * iPow[a[i]] % mod) 
			return puts("YES"), void();
		s1.add(a[i], iPow[a[i]]), s2.add(a[i], Pow[a[i]]);
	}
	puts("NO");
}
int main() {
	Main();
	return 0;
}