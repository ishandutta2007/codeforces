#include <bits/stdc++.h>

int N;
int A[300000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 0; i < 2 * N; ++i) std::cin >> A[i];
	std::sort (A, A + 2 * N);
	long long res = 1LL * (A[N - 1] - A[0]) * (A[2 * N - 1] - A[N]); 
	for (int i = 1; i + N < 2 * N; ++i) res = std::min (res, 1LL * (A[i + N - 1] - A[i]) * (A[2 * N - 1] - A[0]));
	std::cout << res << "\n";
}