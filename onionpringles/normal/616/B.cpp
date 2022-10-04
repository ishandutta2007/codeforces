#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <tuple>

#define mp make_pair
#define mtp make_tuple
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;

int cost[100][100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ni(cost[i][j]);
		}
	}
	int _m = -1;
	for (int i = 0; i < n; i++) {
		_m = max(_m, *min_element(cost[i], cost[i] + m));
	}
	printf("%d", _m);
	return 0;
}