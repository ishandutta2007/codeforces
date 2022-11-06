#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
char s[121323], t[123123];
int nxt[123123];
int is[123123], f[123123], sum[123213], ssum[123123];
int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	for (int i = 2; i <= m; ++i) {
		int p = nxt[i - 1];
		for (; p && t[p + 1] != t[i]; p = nxt[p]);
		p += t[p + 1] == t[i];
		nxt[i] = p;
	}
	is[0] = -1;
	for (int i = 1, p = 0; i <= n; ++i) {
		while (p && s[i] != t[p + 1]) p = nxt[p];
		p += s[i] == t[p + 1];
		if (p == m) is[i] = i - m + 1;
		else is[i] = is[i - 1];
	}
	sum[0] = f[0] = ssum[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (is[i] != -1) f[i] = ssum[is[i] - 1];
		sum[i] = (sum[i - 1] + f[i]) % mod;
		ssum[i] = (ssum[i - 1] + sum[i]) % mod;
	}
	printf("%d", (sum[n] + mod - 1) % mod);
}