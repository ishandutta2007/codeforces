#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
#include <bit>

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

std::vector<std::array<int, 2>> ans;
inline void add(int x, int y, int k) {
	ans.push_back({x * k, y * k});
}
inline void expp(int n, int x, int k) {
	while (n != x)
		add(0, n, k),
		add(n, n, k),
		n *= 2;
}

std::vector<std::array<int, 2>> pans[8] = {
	{},
	{},
	{},
	{{1, 3}, {2, 2}},
	{{1, 3}, {2, 2}},
	{{1, 2}, {1, 3}, {2, 4}, {2, 6}, {4, 4}, {3, 5}, {0, 2}, {2, 2}, {0, 4}, {4, 4}},
	{{1, 2}, {1, 3}, {2, 4}, {2, 6}, {4, 4}, {3, 5}, {2, 6}, {0, 4}, {4, 4}},
	{{1, 2}, {3, 5}, {2, 6}, {4, 4}, {1, 0}, {1, 3}, {1, 7}, {2, 6}, {4, 4}}
};

// n >= 3
// j >= 2
void Solve(int n, int x, int k) {
	if (n == x) {
		Solve(n - 1, x, k);
		return ;
	}
	if (n <= x / 2) {
		Solve(n, x / 2, k);
		F(i, 1, n - 1)
			expp(x / 2, x, k);
		return ;
	}
	if (n <= 7) {
		for (auto [a, b] : pans[n])
			add(a, b, k);
		return ;
	}
	F(i, x / 2 + 1, n)
		add(x - i, i, k);
	// [1 ~ x-n-1], x/2,  k
	// [1 ~ n-x/2], x/2, 2k
	int n1 = x - n - 1;
	int n2 = n - x / 2;
	if (n1 >= 3) {
		Solve(n1, x / 2, k);
		F(i, 1, n1 - 1)
			expp(x / 2, x, k);
	}
	if (n2 >= 3) Solve(n2, x / 2, 2 * k);
	expp(x / 2, x, k);
	if (n1 <= 2)
		F(i, 1, n1)
			expp(i, x, k);
	if (n2 <= 2)
		F(i, 1, n2)
			expp(i, x / 2, 2 * k);
	if (n1 >= 3 && n2 >= 3)
		add(0, x, k);
}

int n;

void Solve() {
	scanf("%d", &n);
	if (n == 2)
		return puts("-1"), void();
	int x = std::bit_ceil((unsigned)n);
	if (n <= 7) {
		ans = pans[n];
	} else {
		ans.clear();
		Solve(n, x, 1);
	}
	add(0, x, 1);
	printf("%d\n", (int)ans.size());
	for (auto [a, b] : ans)
		printf("%d %d\n", a, b);
}