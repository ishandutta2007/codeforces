#include <bits/stdc++.h>

int main () {
	long long N, K;
	std::cin >> N >> K;
	long long one = N / 2 / (K + 1);
	std::cout << one << " " << one * K << " " << N - one * (K + 1) << std::endl;
}