#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
bool Prime[N];
int p[N >> 3], mu[N], tot;
void minit(int x) {
	mu[1] = 1;
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i, mu[i] = -1;
		for(int j = 1; p[j] * i <= x && j <= tot; j++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = - mu[i];
		}
	}
}
ll n, f[N], ans;
long db qpow(long db x, int y) {
	long db res = 1;
	for(; y; x = x * x, y >>= 1) if(y & 1) res *= x;
	return res;
}
ll get(int x) {
	ll l = floor(pow(n, 1.0L / x)) - 1, mid = l + 1, r = l + 2;
	if(qpow(r, x) <= (long db) n) return r;
	if(qpow(mid, x) <= (long db) n) return mid;
	return l;
}
void Main() {
	ans = 0;
	scanf("%lld", &n);
	R(i, 59, 1) f[i] = get(i) - 1, ans += f[i] * mu[i];
	printf("%lld\n", ans);
}
int main() {
	minit(1111);
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}