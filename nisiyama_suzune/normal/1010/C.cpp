#include <bits/stdc++.h>

int N, K;
int A[110000];
int B[110000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) std::cin >> A[i];
	for (int i = 0; i < N; ++i) B[i] = std::__gcd (A[i], K);
	int res = B[0];
	for (int i = 1; i < N; ++i) res = std::__gcd (res, B[i]);
	std::cout << K / res << "\n";
	for (int i = 0; i < K / res; ++i)
		std::cout << i * res << " \n"[i + 1 == K / res];
}