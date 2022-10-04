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

int cnt[2][367];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	for (int i = 0; i < n; i++) {
		char tp; scanf(" %c ", &tp);
		int x = (tp == 'M');
		int a, b; nii(a, b);
		for (int j = a; j <= b; j++) cnt[x][j]++;
	}
	int _max = -1;
	for (int i = 1; i <= 367; i++) {
		_max = max(_max, min(cnt[0][i], cnt[1][i]));
	}
	printf("%d", 2 * _max);
	return 0;
}