#include <bits/stdc++.h>
using namespace std;

int TC, N, K, A[105];

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		set<int> S;
		for (int i = 0; i < N; i++) S.insert(A[i]);
		if (K == 1 && S.size() > 1) {
			printf("-1\n");
			continue;
		}
		long long sumsofar = 0, ans = 0;
		for (int i = 0; i < 1000000000; i++) {
			if (i == 0) sumsofar += K;
			else sumsofar += K-1;
			ans++;
			if (sumsofar >= S.size()) {
				printf("%lld\n", ans);
				break;
			}
		}
	}
}