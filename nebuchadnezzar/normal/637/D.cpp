#include <cstdio>
#include <algorithm>
#include <vector>

int const N = 200200;

int a[N];

int main() {
	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	std::vector<std::pair<int, int>> ans;
	int last = 0;
	for (int i = 0; i < n;) {
		int now = a[i] - last - 1;
		if (d <= 1 || now < s) {
			puts("IMPOSSIBLE");
			return 0;
		}
		ans.emplace_back(0, now);
		last += now;
		int maxTo = last + d;
		++i;
		while (i < n) {
			if (maxTo <= a[i]) {
				break;
			}
			if (a[i] - a[i - 1] - 1 >= s + 1) {
				break;
			}
			++i;
		}
		int to = a[i - 1] + 1;
		ans.emplace_back(1, to - last);
		last = to;
	}
	if (last < m) {
		ans.emplace_back(0, m - last);
	}
	for (auto act : ans) {
		printf("%s %d\n", act.first == 0 ? "RUN" : "JUMP", act.second);
	}
}