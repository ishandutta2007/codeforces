#include <bits/stdc++.h>
using namespace std;

int p[110];
long long S[110];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		S[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			S[i] = S[i - 1] + p[i];
		}
		long long maxj = 0;
		for (int i = 2; i <= n; i++) {
			maxj = max(maxj, ((long long)p[i] * 100 + k - 1) / k - S[i - 1]);
		}
		printf("%I64d\n", maxj);
	}
	return 0;
}