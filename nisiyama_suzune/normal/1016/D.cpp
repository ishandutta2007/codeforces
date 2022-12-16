#include <bits/stdc++.h>

int N, M;
int A[200], B[200];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) std::cin >> A[i];
	for (int i = 0; i < M; ++i) std::cin >> B[i];
	int a = 0, b = 0;
	for (int i = 0; i < N; ++i) a ^= A[i];
	for (int i = 0; i < M; ++i) b ^= B[i];
	if (a != b) return std::cout << "NO\n", 0;
	std::cout << "YES\n" << (a ^ A[0] ^ B[0]);
	for (int i = 1; i < M; ++i) std::cout << " " << B[i];
	std::cout << "\n";
	for (int i = 1; i < N; ++i) {
		std::cout << A[i];
		for (int j = 1; j < M; ++j) std::cout << " 0";
		std::cout << "\n";
	}
	return 0;
}