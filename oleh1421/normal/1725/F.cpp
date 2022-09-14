#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000;
const int LG = 30;

int n, q, l[N], r[N], ans[LG];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", l + i, r + i);
		++r[i];
	}
	for (int j = 0; j < LG; ++j) {
		std::vector<std::pair<int, int> > vec;
		for (int i = 0; i < n; ++i) if (r[i] - l[i] < 1 << j) {
			int k = l[i] >> j << j, rr = r[i] - k, ll = l[i] - k;
			vec.push_back(std::make_pair(ll, 1));
			vec.push_back(std::make_pair(rr, -1));
			vec.push_back(std::make_pair(ll - (1 << j), 1));
			vec.push_back(std::make_pair(rr - (1 << j), -1));
		}
		std::sort(vec.begin(), vec.end());
		int sum = 0;
		ans[j] = n - (int)vec.size() / 4;
		for (int i = 0; i < (int)vec.size();) {
			do {
				sum += vec[i].second;
				++i;
			} while (i < (int)vec.size() && vec[i].first == vec[i - 1].first);
			ans[j] = std::max(ans[j], sum + n - (int)vec.size() / 4);
		}
	}
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[__builtin_ctz(x)]);
	}
	return 0;
}