#include <bits/stdc++.h>

int N, M;
int A[1100], B[1100];

bool eval (double m) {
	m -= 1. * (m + M) / A[0];
	if (m < 0) return false;
	for (int i = 1; i < N; ++i) {
		m -= 1. * (m + M) / B[i];
		if (m < 0) return false;
		m -= 1. * (m + M) / A[i];
		if (m < 0) return false;
	}
	m -= 1. * (m + M) / B[0];
	if (m < 0) return false;
	return true;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) std::cin >> A[i];
	for (int i = 0; i < N; ++i) std::cin >> B[i];
	double l = 0, r = 2E9;
	for (int st = 0; st < 1000; ++st) {
		double m = (l + r) / 2;
		if (eval (m)) r = m;
		else l = m;
	}
	if (r <= 1000000001)
		std::cout << std::fixed << std::setprecision (10) << r << "\n";
	else
		std::cout << "-1\n";
	return 0;
}