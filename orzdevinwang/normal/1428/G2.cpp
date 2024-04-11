#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--) 
#define ll long long 
const int N = 1e6 + 7; 
int n, m, k, sz, t, q;
ll p[6], f[N];
void Push(int v, ll w) { R(i, 1e6, v) f[i] = max(f[i], w + f[i - v]); }
void gg(int v, int w) {
	int now = min(k, (int)1e6 / v);
	for(int i = 1; i < now; i <<= 1) now -= i, Push(v * i, 1ll * w * i); 
	Push(v * now, 1ll * w * now);
}
int main() {
	scanf("%d", &k), sz = 1, k = 3 * (k - 1);
	L(i, 0, 5) scanf("%d", &p[i]);
	L(i, 0, 1e6) {
		int now = 0, x = i, s = x % 10;
		while(x) {
			if(s % 3 == 0) f[i] += 1ll * p[now] * (s / 3);
			x /= 10, ++now, s = x % 10;
		}
	}
	L(i, 0, 5) gg(sz * 3, p[i]), sz *= 10;
	scanf("%d", &q);
	while(q--) scanf("%d", &t), printf("%lld\n", f[t]);
	return 0;
}