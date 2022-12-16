#include <bits/stdc++.h>

int N, L;
long long C[50];

int main () {
	std::cin >> N >> L;
	for (int i = 0; i < N; ++i) std::cin >> C[i];
	for (int i = 0; i < N - 1; ++i) 
		if (C[i + 1] > 2 * C[i]) C[i + 1] = 2 * C[i];
	for (int i = N; i <= 31; ++i) C[i] = 2 * C[i - 1];
	long long ans = 1E18, res = 0;
	for (int i = 31; i >= 0; --i) {
		if ((L >> i) & 1) res += C[i];
		ans = std::min (ans, res + C[i]);
	}
	std::cout << std::min (ans, res) << std::endl;
}