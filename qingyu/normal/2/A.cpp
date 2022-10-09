#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

constexpr int MAXN = 5000;

int n, maxn = -1000, sc[MAXN];

std::string s, maxs, stu[MAXN];

std::map<std::string, int> m, m1;

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> stu[i] >> sc[i];
		m[stu[i]] += sc[i];
	}
	for (int i = 1; i <= n; ++i) maxn = max(maxn, m[stu[i]]);
	for (int i = 1; i <= n; ++i) {
		m1[stu[i]] += sc[i];
		if (m[stu[i]] == maxn and m1[stu[i]] >= maxn) {
			maxs = stu[i];
			break;
		}
	}
	std::cout << maxs;
}