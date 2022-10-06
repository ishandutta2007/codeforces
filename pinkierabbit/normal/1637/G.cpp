#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#include <array>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

vector<array<int, 2>> ans;
inline void add(int x, int y, int k) {
	ans.push_back({x * k, y * k});
}
inline void mult(int n, int x, int k) {
	add(x, x, k);
	F(p, 1, n - 2) {
		add(0, x, k);
		add(x, x, k);
	}
	add(0, x * 2, k);
}
inline void expp(int n, int x, int k) {
	while (n != x)
		add(0, n, k),
		add(n, n, k),
		n *= 2;
}

vector<array<int, 2>> pans[8] = {
	{},
	{},
	{},
	{{1, 3}, {2, 2}, {0, 4}},
	{{1, 3}, {2, 2}, {0, 4}},
	{{1, 2}, {1, 3}, {2, 4}, {2, 6}, {4, 4}, {3, 5}, {0, 2}, {2, 2}, {0, 4}, {4, 4}, {0, 8}},
	{{1, 2}, {1, 3}, {2, 4}, {2, 6}, {4, 4}, {3, 5}, {2, 6}, {0, 4}, {4, 4}, {0, 8}},
	{{1, 2}, {3, 5}, {2, 6}, {4, 4}, {1, 0}, {1, 3}, {1, 7}, {2, 6}, {4, 4}, {0, 8}}
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
		mult(n, x / 2, k);
		return ;
	}
	if (n <= 7) {
		for (auto [a, b] : pans[n])
			add(a, b, k);
		return ;
	}
	F(i, x / 2 + 1, n)
		add(x - i, i, k);
	int n1 = x - n - 1;
	int n2 = n - x / 2;
	// [1 ~ x-n-1], x/2,  k
	// [1 ~ n-x/2], x/2, 2k
	if (n1 == 0) {
		Solve(n2, x / 2, 2 * k);
		ans.pop_back();
		expp(x / 2, x, k);
		add(0, x, k);
	} else if (n1 == 1) {
		Solve(n2, x / 2, 2 * k);
		ans.pop_back();
		expp(1, x, k);
		expp(x / 2, x, k);
		add(0, x, k);
	} else if (n1 == 2) {
		Solve(n2, x / 2, 2 * k);
		ans.pop_back();
		expp(1, x, k);
		expp(2, x, k);
		expp(x / 2, x, k);
		add(0, x, k);
	} else {
		Solve(n1, x / 2, k);
		mult(n1 + 1, x / 2, k);
		if (n2 == 1) {
			ans.pop_back();
			expp(1, x / 2, 2 * k);
			add(0, x, k);
		} else if (n2 == 2) {
			ans.pop_back();
			expp(1, x / 2, 2 * k);
			expp(2, x / 2, 2 * k);
			add(0, x, k);
		} else {
			Solve(n2, x / 2, 2 * k);
		}
	}
}

int n;

void Solve() {
	scanf("%d", &n);
	if (n == 2)
		return puts("-1"), void();
	if (n <= 7) {
		ans = pans[n];
	} else {
		ans.clear();
		if ((n & -n) == n) --n;
		int j = 32 - __builtin_clz(n);
		Solve(n, 1 << j, 1);
	}
	printf("%d\n", (int)ans.size());
	for (auto [a, b] : ans)
		printf("%d %d\n", a, b);
}