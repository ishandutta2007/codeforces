#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 100000, maxC = 300000;
int n, m, ans;
map<int, int> f[maxN + 10];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i][-1] = 0;
	for (int i = 1; i <= m; ++i) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);
		map<int, int>::iterator it = --f[l].lower_bound(w), itt = --f[r].upper_bound(w);
		ans = max(ans, it -> second + 1);
		if (itt->second < it->second + 1) {
			f[r][w] = it->second + 1;
			itt = f[r].upper_bound(w);
			while (itt != f[r].end() && itt->second <= it->second + 1)
				f[r].erase(itt++);
		}
	}
	printf("%d", ans);
}