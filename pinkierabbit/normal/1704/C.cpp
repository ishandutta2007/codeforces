// 10703

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using std::scanf, std::printf;

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int MM = 100005;

int n, m;
int a[MM];

void Solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	std::sort(a + 1, a + m + 1);
	a[m + 1] = a[1] + n;
	std::vector<int> s;
	for (int i = 1; i <= m; ++i)
		s.push_back(a[i + 1] - a[i] - 1);
	std::sort(s.begin(), s.end(), std::greater());
	int ans = 0;
	int c = 0;
	for (int x : s) {
		int y = x - 2 * c;
		if (y <= 0)
			break;
		if (y >= 3)
			ans += y - 1,
			c += 2;
		else
			ans += 1,
			++c;
	}
	printf("%d\n", n - ans);
}