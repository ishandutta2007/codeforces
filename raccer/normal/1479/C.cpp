#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[40];

int main () {
	int l, r; scanf("%d%d", &l, &r); 
	printf("YES\n");
	int n = 32, m = 0;
	for (int i = 31; i >= 12; i--) {
		for (int j = 32; j > i; j--) {
			from[i].push_back(mp(j, j == 32 ? 1 : 1 << 31 - j)), m++;
		}
	}
	int tmp = r - l + 1, pos = 1;
	if (l != 1) from[1].push_back(mp(2, l - 1)), m++, pos = 2;
	from[pos].push_back(mp(32, 1)), tmp--, m++;
	int cur = 1;
	for (int i = 0; i < 20; i++) {
		if (tmp >> i & 1) from[pos].push_back(mp(31 - i, cur)), cur += 1 << i, m++;
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j].fi, d = from[i][j].se;
			printf("%d %d %d\n", i, v, d);
		}
	}
	return 0;
}