#include <bits/stdc++.h>

int N;
long long A[110000];
long long mark[110000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 1; i <= N; ++i)
		std::cin >> A[i];
	long long res = 0;
	for (int i = 1; i <= N; ++i) 
		mark[i] = std::max (mark[i - 1], A[i]);
	for (int i = N; i >= 1; --i)
		mark[i] = std::max (mark[i + 1] - 1, mark[i]);
	for (int i = 1; i <= N; ++i) res += mark[i] - A[i];
	std::cout << res << std::endl;
}