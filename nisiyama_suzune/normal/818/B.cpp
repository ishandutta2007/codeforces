#include <bits/stdc++.h>

int A[11000];
int L[11000];
bool used[11000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
		A[i] = -1;
	int lst = -1;
	for (int i = 0; i < M; ++i) {
		std::cin >> L[i];
		--L[i];
		if (lst != -1) {
			A[lst] = (L[i] - lst + N) % N;
		}
		lst = L[i];
	}
	for (int i = 1; i < M; ++i) {
		if (!((A[L[i - 1]] + L[i - 1]) % N == L[i])) {
			puts ("-1");
			return 0;
		}
	}
	for (int i = 0; i < N; ++i) 
		if (A[i] >= 0) used[A[i]] = true;
	for (int i = 0; i < N; ++i)
		if (A[i] < 0)
			for (int j = 0; j < N; ++j)
				if (!used[j]) {
					A[i] = j;
					used[j] = true;
					break;
				}
	for (int i = 0; i < N; ++i) 
		for (int j = i + 1; j < N; ++j) 
			if (A[i] == A[j]) {
				puts ("-1");
				return 0;
			}
	for (int i = 0; i < N; ++i)
		printf ("%d%c", A[i] == 0 ? N : A[i], " \n"[i == N - 1]);
}