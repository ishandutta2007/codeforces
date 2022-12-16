#include <bits/stdc++.h>

int N, M, Q;
std::pair <int, int> cost[1 << 12];
int cnt[1 << 12];
std::pair <int, int> sum[1 << 12][1 << 12];
std::string str;

int lowbit (int x) { return x & (-x); }

int to_int (const std::string &s) {
	int res = 0;
	for (int i = 0; i < s.size (); ++i) 
		if (s[i] == '1') res |= 1 << i;
	return res;
}

int to_int_r (const std::string &s) {
	int res = 0;
	for (int i = 0; i < s.size (); ++i) 
		if (s[i] == '0') res |= 1 << i;
	return res;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M >> Q;
	for (int i = 0; i < N; ++i) {
		int w; std::cin >> w; cost[1 << i].first = w;
	}
	for (int mask = 0; mask < (1 << N); ++mask) 
		cost[mask] = std::make_pair (cost[mask ^ lowbit (mask)].first + cost[lowbit (mask)].first, mask);
	std::sort (cost, cost + (1 << N));
	for (int i = 0; i < M; ++i) {
		std::cin >> str; ++cnt[to_int_r (str)];
	}
	for (int i = 0; i < 1 << N; ++i) {
		for (int j = 0; j < 1 << N; ++j)
			sum[i][j] = std::make_pair (cost[j].first, cnt[cost[j].second ^ i]);
		for (int j = 1; j < 1 << N; ++j)
			sum[i][j].second += sum[i][j - 1].second;
//		for (int j = 0; j < 1 << N; ++j)
//			std::cout << "(" << sum[i][j].first << ", " << sum[i][j].second << ") ";
//		std::cout << "\n";
	}
	for (int q = 0; q < Q; ++q) {
		int ind, K;
		std::cin >> str >> K; ind = to_int (str);
		int bo = std::upper_bound (sum[ind], sum[ind] + (1 << N), std::make_pair (K, (int) 2E9)) - sum[ind];
//		std::cout << "bo = " << bo << "\n";
		if (bo == 0) std::cout << 0 << "\n";
		else std::cout << sum[ind][bo - 1].second << "\n";
	}
}