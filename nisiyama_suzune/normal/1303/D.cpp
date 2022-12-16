#include <bits/stdc++.h>

int T;
long long N;
int A[110000];
int M;
int cnt[60];

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%lld%d", &N, &M);
		for (int i = 0; i < M; ++i) scanf("%d", &A[i]);
		for (int i = 0; i < 60; ++i) cnt[i] = 0;
		for (int i = 0; i < M; ++i) ++cnt[__builtin_ctz(A[i])];
		int leftover = 0, deficit = -1;
		long long ans = 0;
		for (int i = 0; i < 60; ++i) {
			leftover = leftover / 2 + cnt[i];
			if (N >> i & 1ll) {
				if (leftover) --leftover;
				else if (deficit == -1) deficit = i;
			}
			if (leftover && deficit != -1) {
				ans += i - deficit;
				--leftover;
				deficit = -1;
			}
		}
		printf("%lld\n", deficit == -1 ? ans : -1ll);
	}
}