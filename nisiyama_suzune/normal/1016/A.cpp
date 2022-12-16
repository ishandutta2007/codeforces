#include <bits/stdc++.h>

int N, M;
int A[210000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	int cur = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
		std::cout << (A[i] / M) + (cur + A[i] % M) / M << " \n"[i + 1 == N];
		cur = (cur + A[i] % M) % M;
	}
}