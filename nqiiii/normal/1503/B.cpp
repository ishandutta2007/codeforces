#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n;
int c[2];
queue<pair<int, int> > b[2];

void color(int d, int c) {
	pair<int, int> e = b[d].front();
	b[d].pop();
	printf("%d %d %d\n", c, e.first, e.second);
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			b[(i + j) % 2].push(make_pair(i, j));
	for (int t = 1; t <= n * n; ++t) {
		int c; scanf("%d", &c);
		if (b[0].empty()) {
			color(1, c == 2 ? 3 : 2);
		} else if (b[1].empty()) {
			color(0, c == 1 ? 3 : 1);
		} else if (c == 1) color(1, 2);
		else color(0, 1);
	}
}