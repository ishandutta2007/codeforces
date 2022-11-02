#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int n, dp[10], pd[10];
char s[13];

int main() {
	scanf("%s", s);
	n = strlen(s);
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	for (int i = n - 1; ~i; --i) {
		memset(pd, -1, sizeof pd);
		for (int t, j = 0; j < 10; ++j) if(~(t = dp[j])) {
			for (int x = 0; x < 10; ++x) for (int y = 0; y < 10; ++y) {
				int z = x + y + j;
				if(z % 10 == s[i] - '0') {
					pd[z / 10] = max(pd[z / 10], t + x + y);
				}
			}
		}
		memcpy(dp, pd, sizeof dp);
	}
	printf("%d\n", dp[0]);
	return 0;
}