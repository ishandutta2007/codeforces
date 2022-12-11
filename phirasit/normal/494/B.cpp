#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define N 100010

long long dp[N], sum[N], sum2[N];

char s[N], t[N];
int T[N], C[N];

int l, lt;

void build_KMP(void) {
	T[0] = -1;
	int k = -1;
	for(int i = 0;i < lt;) {
		while(k > -1 && t[i] != t[k]) {
			k = T[k];
		}
		i++;
		k++;
		if(t[i] == t[k]) {
			T[i] = T[k];
		}else {
			T[i] = k;
		}
	}
}
int main() {
	scanf("%s%s", s, t);
	l = strlen(s);
	lt = strlen(t);
	build_KMP();
	int k = 0;
	for(int j = 0;j < l;) {
		while(k > -1 && t[k] != s[j]) {
			k = T[k];
		}
		k++;
		j++;
		if(k >= lt) {
			C[j-1] = 1;
			k = T[k];
		}
	}
	dp[0] = sum[0] = sum2[0] = 0;
	int ls = -1;
	for(int i = 0;i < l;i++) {
		if(C[i]) {
			ls = i;
		}
		if(ls == -1) {
			dp[i] = 0;
		}else {
			if(ls-lt >= 0) {
				dp[i] = sum2[ls-lt] + ls-lt+2;
			}else {
				dp[i] = 1;
			}
		}
		sum[i] = (sum[i-1] + dp[i]) % MOD;
		sum2[i] = (sum2[i-1] + sum[i]) % MOD;
	}
	printf("%I64d\n", sum[l-1] % MOD);
	return 0;
}