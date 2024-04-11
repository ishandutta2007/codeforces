#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int tbl[500][500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k; scanf("%d %d", &n, &k);
	k--;
	int fill = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			tbl[i][j] = ++fill;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = k; j < n; j++) {
			tbl[i][j] = ++fill;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) sum += tbl[i][k];
	printf("%d\n", sum);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", tbl[i][j]);
		}
		printf("\n");
	}
}