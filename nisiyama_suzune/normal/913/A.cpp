#include <bits/stdc++.h>

int main () {
	int N, M;
	std::cin >> N >> M;
	if (N >= 30) std::cout << M << std::endl;
	else {
		int res = 1;
		for (int i = 0; i < N; ++i) res *= 2;
		std::cout << M % res << std::endl;
	}
}