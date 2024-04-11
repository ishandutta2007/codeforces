#include <bits/stdc++.h>

int T;
long long N, G, B;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%lld%lld%lld", &N, &G, &B);
		long long cycle = (N / 2) / B;
		long long remB = N / 2 - cycle * B;
		long long length = cycle * (G + B) + G + remB;
		if (length >= N) {
			printf("%lld\n", N);
			continue;
		}
		long long cycG = ((N - length) + G - 1) / G;
		long long days = (cycG - 1) * B + (N - length);
		printf("%lld\n", length + (B - remB) + days);
	}
}