#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char buf[500][500];

int rowdyn[500][500];
int coldyn[500][500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf(" %s", buf[i]);
	}
	for (int i = 0; i < h; i++) {
		rowdyn[i][0] = 0;
		for (int j = 1; j < w; j++) {
			rowdyn[i][j] = rowdyn[i][j - 1];
			if (buf[i][j] == '.' && buf[i][j - 1] == '.') {
				rowdyn[i][j]++;
			}
		}
	}
	for (int j = 0; j < w; j++) {
		coldyn[j][0] = 0;
		for (int i = 1; i < h; i++) {
			coldyn[j][i] = coldyn[j][i - 1];
			if (buf[i][j] == '.' && buf[i - 1][j] == '.') coldyn[j][i]++;
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int r1, r2, c1, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--; c1--; r2--; c2--;
		int ans = 0;
		for (int i = r1; i <= r2; i++) {
			ans += rowdyn[i][c2];
			if (c1 > 0) {
				ans -= rowdyn[i][c1 - 1];
				if (buf[i][c1 - 1] == '.' && buf[i][c1] == '.') ans--;
			}
		}
		for (int i = c1; i <= c2; i++) {
			ans += coldyn[i][r2];
			if (r1 > 0) {
				ans -= coldyn[i][r1 - 1];
				if (buf[r1 - 1][i] == '.' && buf[r1][i] == '.') ans--;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}