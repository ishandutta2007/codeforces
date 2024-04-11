#include <bits/stdc++.h>
using namespace std;

int a[100010];
int pos[50];

int main () {
	int n; scanf("%d", &n);
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < 30; j++) {
			if (a[i] >> j & 1) {
				if (pos[j] == -1) pos[j] = i;
				else if (pos[j] != -2) pos[j] = -2;
			}
		}
	}
	for (int j = 29; j >= 0; j--) {
		if (pos[j] < 0) continue;
		printf("%d ", a[pos[j]]);
		for (int i = 0; i < n; i++) {
			if (i == pos[j]) continue;
			printf("%d ", a[i]);
		}
		printf("\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}