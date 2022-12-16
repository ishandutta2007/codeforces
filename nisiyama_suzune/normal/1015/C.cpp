#include <bits/stdc++.h>

int N, M;
std::pair <int, int> S[110000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) std::cin >> S[i].first >> S[i].second;
	std::sort (S, S + N, [&] (std::pair <int, int> a, std::pair <int, int> b) { return a.first - a.second > b.first - b.second; });
	long long res = 0; int ans = 0;
	for (int i = 0; i < N; ++i) res += S[i].first;
	for (int i = 0; i < N && res > M; ++i) {
		++ans; res -= S[i].first - S[i].second;
	}
	if (res > M) std::cout << -1 << "\n";
	else std::cout << ans << "\n";
}