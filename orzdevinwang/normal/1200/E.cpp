#include<bits/stdc++.h>
#define N 1919810
#define mod 998244353
#define G 917120411
using namespace std;
int m, po[N], has[N], gas[N], len, n;
char s[N], p[N];
int main() {
	po[0] = 1;
	for(int i = 1; i <= 1e6; i++) po[i] = 1ll * po[i - 1] * G % mod;
	scanf("%d", &m), --m;
	scanf("%s", s + 1), len = strlen(s + 1);
	for(int i = 1; i <= len; i++) has[i] = (has[i - 1] + 1ll * s[i] * po[i] % mod) % mod;
	while(m--) {
		scanf("%s", p + 1), n = strlen(p + 1);
		for(int i = 1; i <= n; i++) gas[i] = (gas[i - 1] + 1ll * p[i] * po[i] % mod) % mod;
		int th = 1;
		for(int i = 1; i <= min(len, n); i++) 
			if(1ll * gas[i] * po[len - i] % mod == (has[len] - has[len - i] + mod) % mod) th = i + 1;
		for(int i = th; i <= n; i++) {
			s[++len] = p[i];
			has[len] = has[len - 1];
			(has[len] += 1ll * s[len] * po[len] % mod) %= mod;
		}
	}
	printf("%s\n", s + 1);
	return 0;
}