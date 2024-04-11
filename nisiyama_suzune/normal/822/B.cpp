#include <bits/stdc++.h>

int N, M;
std::string S, T;
int ans = -1, best = 1E9;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> N >> M >> S >> T;
	for (int i = 0; i < T.size () - S.size () + 1; ++i) {
		int cur = 0;
		for (int j = 0; j < S.size (); ++j)
			if (S[j] != T[i + j]) ++cur;
		if (best > cur) {
			best = cur;
			ans = i;
		}
	}
	std::cout << best << std::endl;
	for (int i = 0; i < S.size (); ++i)
		if (S[i] != T[ans + i]) std::cout << i + 1 << " ";
}