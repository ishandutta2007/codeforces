#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))

using namespace std;

char buf[100][101];

inline int nc2(int x) { return x*(x - 1) / 2; }

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; ni(n);
	int ans = 0;
	for (int i = 0; i < n; i++) scanf("%s", buf[i]);
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cnt += (buf[i][j] == 'C');
		}
		ans += nc2(cnt);
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cnt += (buf[j][i] == 'C');
		}
		ans += nc2(cnt);
	}
	printf("%d", ans);
	return 0;
}