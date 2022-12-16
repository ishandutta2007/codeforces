#include <bits/stdc++.h>

const long long INF = 1E9;

int N;
long long A[110000];
long long F[5100][5100], S[5100][5100];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 1; i <= N; ++i) std::cin >> A[i];
	for (int k = 1; k <= (N + 1) / 2; ++k) {
		long long minval = INF;
		for (int i = 1; i <= N; ++i) {
			if (k >= 2 && i >= 3) {
				F[k][i] = F[k - 1][i - 2] + std::max (std::min (A[i - 1], A[i - 2] - 1) - (A[i] - 1), 0ll) + std::max (A[i + 1] - (A[i] - 1), 0ll);
				minval = std::min (minval, F[k - 1][i - 2]);
			} else F[k][i] = (k == 1) ? (std::max (A[i - 1] - (A[i] - 1), 0ll) + std::max (A[i + 1] - (A[i] - 1), 0ll)) : INF;
			F[k][i] = std::min (F[k][i], minval + std::max (A[i - 1] - (A[i] - 1), 0ll) + std::max (A[i + 1] - (A[i] - 1), 0ll));
//			std::cout << F[k][i] << " \n"[i == N];
		}	
	}
	for (int k = 1; k <= (N + 1) / 2; ++k) {
		long long ans = INF;
		for (int i = 1; i <= N; ++i) ans = std::min (ans, F[k][i]);
		std::cout << ans << " \n"[k == (N + 1) / 2];
	}
}