// 10703

#include <cstdio>
#include <algorithm>
using std::scanf, std::printf;

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int MN = 100005;

int n, m;
LL v[MN];

void Solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		v[i] = 0;
		LL x;
		for (int j = 1; j <= m; ++j)
			scanf("%lld", &x),
			v[i] += x * j;
	}
	int p = (int)(std::max_element(v + 1, v + n + 1) - v);
	printf("%d %lld\n", p, v[p] - v[p % n + 1]);
}