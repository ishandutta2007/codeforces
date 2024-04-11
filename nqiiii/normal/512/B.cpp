#include <bits/stdc++.h>
using namespace std;
const int maxn = 300, inf = 0x3f3f3f3f;
int n, l[maxn + 10], c[maxn + 10];
map<int, int> f[2];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &l[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i & 1] = f[~i & 1];
		for (auto j: f[~i & 1]) {
			int w = __gcd(j.first, l[i]);
			if (f[i & 1].find(w) == f[i & 1].end())
				f[i & 1][w] = inf;
			f[i & 1][w] = min(f[i & 1][w], j.second + c[i]);
		}
	}
	if (f[n & 1].find(1) == f[n & 1].end()) printf("-1");
	else printf("%d", f[n & 1][1]);
}