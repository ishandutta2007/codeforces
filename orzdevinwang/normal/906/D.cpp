#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
unordered_map<int, int> mp;
int phi(int x) {
	if(mp.count(x)) return mp[x];
	int now = x, sav = x;
	L(i, 2, sqrt(x)) if(x % i == 0) {
		now /= i, now *= i - 1;
		while(x % i == 0) x /= i; 
	} 
	if(x != 1) now /= x, now *= x - 1;
	return mp[sav] = now;
}
int Mod(ll x, int mod) {
	if(x < mod) return x;
	return x % mod + mod;
}
int qpow(int x, int y, int mod) {
	int res = 1;
	for(; y; x = Mod(1ll * x * x, mod), y >>= 1) if(y & 1) res = Mod(1ll * res * x, mod);
	return res; 
}
int n, m, f[N];
int calc(int l, int r, int mod) {
	if(l == r || mod == 1) return Mod(f[l], mod);
	return qpow(f[l], calc(l + 1, r, phi(mod)), mod);
}
int mod;
int main() {
	scanf("%d%d", &n, &mod);
	L(i, 1, n) scanf("%d", &f[i]);
	scanf("%d", &m);
	while(m--) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", calc(l, r, mod) % mod);
	}
	return 0;
}