#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> m[2501];
int q, t, a,b,c,d;

pair<int, int> check(int r, int c) {
	for (int i = r; i >= 1; i--) {
		auto it = m[i].upper_bound(c);
		if (it != m[i].begin()) {
			it--;
			if (it->second.first >= r && it->second.second >= c)
				return{ i, it->first };
		}
	}
	return{ -1, -1 };
}

int main() {
	scanf("%d%d%d", &q, &q, &q);
	while (q--) {
		scanf("%d%d%d%d%d", &t, &a, &b, &c, &d);
		if (t == 1) m[a][b] = { c, d };
		if (t == 2) m[a].erase(b);
		if (t == 3) {
			pair<int, int> c1 = check(a, b), c2 = check(c, d);
			if (c1 == c2) printf("Yes\n");
			else printf("No\n");
		}
	}
}