#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e6 + 7; 
int n, m, k, t, sz, q;
ll p[6], f[N];
void Push(int v, ll w) { R(i, 1e6, v) f[i] = max(f[i], w + f[i - v]); }
ll get(int x) {
	ll res = 0; int now = 0;
	while(x) {
		int s = x % 10;
		if(s % 3 == 0) res += 1ll * p[now] * (s / 3);
		x /= 10, ++now;
	}
	return res;
}
void gg(int v, int w) {
	int now = min(k, (int)1e6 / v);
	for(int i = 1; i < now; i <<= 1) now -= i, Push(v * i, 1ll * w * i); 
	Push(v * now, 1ll * w * now);
}
int main() {
	scanf("%d", &k), sz = 1, k = 3 * (k - 1);
	L(i, 0, 5) scanf("%d", &p[i]);
	L(i, 0, 1e6) f[i] = get(i);
	L(i, 0, 5) gg(sz * 3, p[i]), sz = sz * 10;
	scanf("%d", &q);
	while(q--) scanf("%d", &t), printf("%lld\n", f[t]);
	return 0;
}