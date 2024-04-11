#include <bits/stdc++.h>

const int N = 3e5 + 50;

inline int lowbit(int x) {
	return x & -x;
}

int n, q;
long long x[N], w[N], t[N], ans[N];

inline void add(int p, long long v) {
	for (; p; p -= lowbit(p))
		t[p] = std::min(t[p], v);
}
inline long long query(int p) {
	long long ans = 5e18;
	for (; p < N; p += lowbit(p))
		ans = std::min(ans, t[p]);
	return ans;
}


int main() {
	memset(t, 0x3f, sizeof t);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> q;
	std::vector<int> mins, maxs;
	std::vector<std::vector<std::pair<int, int>>> queries(n + 1, std::vector<std::pair<int, int>>());
	std::vector<std::vector<std::pair<int, long long>>> modifies(n + 1, std::vector<std::pair<int, long long>>()); 
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i] >> w[i];
	}
	for (int i = 1; i <= q; ++i) {
		int l, r;
		std::cin >> l >> r;
		queries[r].emplace_back(i, l);
	}
	auto addp = [&](int i, int j) {
		if (i > j) std::swap(i, j);
		modifies[j].emplace_back(i, (x[j] - x[i]) * (w[i] + w[j]));
	};
	auto insert = [&](auto &vec, int x, auto cond) {
		while (!vec.empty() && cond(x, vec.back())) vec.pop_back();
		if (!vec.empty()) {
			addp(vec.back(), x);
		}
		vec.emplace_back(x);
	};
	for (int i = 1; i <= n; ++i) {
		insert(mins, i, [&](int x, int k) { return w[k] > w[x]; });
	}
	mins.clear();
	for (int i = n; i >= 1; --i) {
		insert(mins, i, [&](int x, int k) { return w[k] > w[x]; });
	}
	for (int r = 1; r <= n; ++r) {
		for (auto [i, v] : modifies[r]) {
			add(i, v);
		}
		for (auto [i, l] : queries[r]) {
			ans[i] = query(l);
		}
	}
	for (int i = 1; i <= q; ++i) {
		std::cout << ans[i] << '\n';
	}
}