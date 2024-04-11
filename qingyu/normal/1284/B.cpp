#include <bits/stdc++.h>

const int N = 1e6 + 50;

int a[N], fst[N], lst[N];
bool ok[N];

int t[N];
std::vector<std::pair<int, int>> vec;

inline int lowbit(int x) { return x & -x; }

inline void add(int p, int v) {
	for (; p < N; p += lowbit(p))
		t[p] += v;
}
inline int qry(int p) {
	int r = 0;
	for (; p; p -= lowbit(p))
		r += t[p];
	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	int cntok = 0;
	for (int i = 1; i <= n; ++i) {
		int l;
		std::cin >> l;
		for (int i = 1; i <= l; ++i) {
			std::cin >> a[i];
			a[i] = 1e6 + 1 - a[i];
		}
		bool allsame = true;
		for (int i = 1; i < l; ++i)
			if (a[i] != a[i + 1])
				allsame = false;
		if (allsame) ok[i] = false;
		else ok[i] = !std::is_sorted(a + 1, a + l + 1);
		if (ok[i]) {
			++cntok;
		}
		else {
			add(a[l], 1);
			vec.emplace_back(a[1], a[l]);
		}
	}
	long long ans = 1ll * n * n;
	for (auto [x, y] : vec) {
		ans -= qry(x);
	}
	std::cout << ans << '\n';
	return 0;
}