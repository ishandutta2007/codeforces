#include <stdio.h>

#define N 1000010
#define ALPHA 26ll
#define MOD 1000000007ll

long long ans = 1ll;
long long pw[N];

int Z[N];
int ls = 0;

char str[N];
int n, m, p;

int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	p = 0;
	while(str[p+1]) {
		p++;
	}

	Z[1] = 0;
	int mx = 1;
	for(int i = 2;i <= p;i++) {
		Z[i] = (mx + Z[mx] - 1 >= i ? min(Z[i - mx + 1], mx + Z[mx] - i + 1) : 0);
		while(str[Z[i] + 1] == str[i + Z[i]]) {
			Z[i]++;
		}
		if(i + Z[i] - 1 >= mx + Z[mx] - 1) {
			mx = i;
		}
	}
	pw[0] = 1ll;
	for(int i = 1;i <= n;i++) {
		pw[i] = (pw[i-1] * ALPHA) % MOD;
	}
	for(int i = 0;i < m;i++) {
		int y;
		scanf("%d", &y);
		if(ls == 0) {
			ans = pw[y - 1];
		}else {
			if(ls + p - 1 < y) {
				ans = ans * pw[y - (ls + p - 1) - 1];
			}else {
				int x = y - ls + 1;
				if(x + Z[x] - 1 < p) {
					ans = 0ll;
				}
			}
		}
		if(ans >= MOD) {
			ans %= MOD;
		}
		ls = y;
	}
	if(ls > 0) {
		ans = (ans * pw[n - (ls + p - 1)]) % MOD;
	}else {
		ans = (ans * pw[n]) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}