#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int n, cnt[66], ans;
ll f[N];
void Main() {
	n = read();
	ans = 0;
	L(i, 0, 59) cnt[i] = 0;
	L(i, 1, n) {
		scanf("%lld", &f[i]);
		L(j, 0, 59) cnt[j] += ((f[i] >> j) & 1);
	}
	L(i, 1, n) {
		int aa = 0, bb = 0;
		L(j, 0, 59) {
			if((f[i] >> j) & 1) (aa += (1LL << j) % mod * cnt[j] % mod) %= mod;
		}
		L(j, 0, 59) {
			if((f[i] >> j) & 1) (bb += (1LL << j) % mod * n % mod) %= mod;
			else (bb += (1LL << j) % mod * cnt[j] % mod) %= mod;
		}
		(ans += 1ll * aa * bb % mod) %= mod;
	}
	printf("%d\n", ans);
}
int main() {
	int T = read(); 
	while(T--) Main(); 
	return 0;
}