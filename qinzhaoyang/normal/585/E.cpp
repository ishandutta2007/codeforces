#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10 , M = 1e7 + 10 , P = 1000000007;

int n, m, c[M], s[M], p[M], cnt, mu[M], g[M], _[N], ans;

int main() {
	scanf("%d" , &n);
	for(int i = 1 , a; i <= n; i++) scanf("%d" , &a) , c[a]++ , m = max(a , m);
	mu[1] = g[1] = 1;
	for(int i = 2; i <= m; i++) {
		if(!g[i]) p[++cnt] = i , g[i] = i , mu[i] = -1;
		for(int j = 1; p[j] * i <= m && j <= cnt && g[i] >= p[j]; j++) {
			g[p[j] * i] = p[j];
			if(g[i] == p[j]) mu[i * p[j]] = 0;
			else mu[i * p[j]] = -mu[i];
		}
	}
	for(int j = 1; j <= cnt; j++)
		for(int i = m / p[j]; i; i--)
			c[i] += c[i * p[j]];
	for(int i = 1; i <= m; i++) mu[i] *= c[i];
	for(int j = 1; j <= cnt; j++)
		for(int i = 1; i * p[j] <= m; i++)
			mu[i * p[j]] = (mu[i * p[j]] + mu[i]) % P;
	_[0] = 1; for(int i = 1; i <= 500000; i++) _[i] = (_[i - 1] * 2) % P;
	for(int i = 1; i <= m; i++) s[i] = _[c[i]] - 1; 
	for(int j = 1; j <= cnt; j++)
		for(int i = 1; i * p[j] <= m; i++)
			s[i] = (s[i] - s[i * p[j]]) % P;
	for(int i = 2; i <= m; i++) ans = (ans + 1ll * mu[i] * s[i] % P) % P;
	printf("%d\n" , (ans + P) % P);
	return 0;
}