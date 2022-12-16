#include <bits/stdc++.h>

int N, M;
int Q;
std::string S, T;
int occur[11000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M >> Q;
	std::cin >> S >> T;
	for (int i = 0; i + T.size () <= S.size (); ++i) {
		occur[i] = 1;
		for (int j = 0; j < T.size (); ++j) if (T[j] != S[i + j]) occur[i] = 0;
	}
	for (int i = 0; i < S.size (); ++i) occur[i] += occur[i - 1];
	for (int q = 0; q < Q; ++q) {
		int u, v; std::cin >> u >> v;
		if (v - M < 0 || v - M <= u - 2) std::cout << 0 << "\n";
		else if (u - 2 >= 0) std::cout << occur[v - M] - occur[u - 2] << "\n";
		else std::cout << occur[v - M] << "\n";
	}
}