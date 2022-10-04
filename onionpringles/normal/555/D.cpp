#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>

int pos[200000];
int revpos[200000];
int peg[200000];
int rad[200000];

int upper_bound(int begin, int end, int val) {
	int l = begin;
	int u = end;
	while (l != u) {
		int mid = (l + u) / 2;
		if (peg[mid] > val) u = mid;
		else l = mid + 1;
	}
	return u;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) {
		for (int i = 0; i < m; i++) puts("1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		pos[i] = i;
		scanf("%d", peg + i);
	}
	std::sort(pos, pos + n, [&](const int& x, const int &y)->bool {return peg[x] < peg[y]; });
	std::sort(peg, peg + n);
	rad[0] = peg[1] - peg[0];
	rad[n - 1] = peg[n - 1] - peg[n - 2];
	for (int i = 1; i < n - 1; i++) rad[i] = std::min(peg[i + 1] - peg[i], peg[i] - peg[i - 1]);
	for (int i = 0; i < n; i++) revpos[pos[i]] = i;
	for (int i = 0; i < m; i++) {
		int a, l;
		scanf("%d %d", &a, &l); a--;
		a = revpos[a];
		int stat = -1;

		int x = upper_bound(a, n, peg[a] + l);
		x--;
		l -= (peg[x] - peg[a]);
		stat = 1;
		a = x;
		int j;
		for (j = 0; j < 2000; j++) {
			if (l < rad[a]) {
				printf("%d\n", pos[a] + 1);
				break;
			}
			if (stat == -1) {
				int x = upper_bound(a, n, peg[a] + l);
				x--;
				l %= 2*(peg[x] - peg[a]);
				x = upper_bound(a, n, peg[a] + l);
				x--;
				l -= peg[x] - peg[a];
				stat = 1;
				a = x;
			}
			else {
				int x = upper_bound(0, a, peg[a] - l - 1);
				l %= 2*(peg[a] - peg[x]);
				x = upper_bound(0, a, peg[a] - l - 1);
				l -= (peg[x] - peg[a]);
				stat = -1;
				a = x;
			}
		}
		assert(j != 2000);

	}

	return 0;
}