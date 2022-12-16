#include <bits/stdc++.h>

int N;
int A[1100000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	if (N % 4 == 2) { std::cout << "! -1" << std::endl; return 0; }
	std::cout << "? " << N << std::endl;
	std::cin >> A[N];
	std::cout << "? " << N / 2 << std::endl;
	std::cin >> A[N / 2];
	if (A[N / 2] == A[N]) { std::cout << "! " << N / 2 << std::endl; return 0; }
	A[0] = A[N];
	int l = 0, r = N / 2;
	while (l <= r) {
		int m = (l + r) / 2;
		std::cout << "? " << m << std::endl;
		std::cin >> A[m];
		std::cout << "? " << m + N / 2 << std::endl;
		std::cin >> A[m + N / 2];
		if (A[m] == A[m + N / 2]) { std::cout << "! " << m << std::endl; return 0; }
		if (1LL * (A[l] - A[l + N / 2]) * (A[m] - A[m + N / 2]) < 0) r = m;
		else l = m;
	}
	std::cout << "! -1" << std::endl;
}