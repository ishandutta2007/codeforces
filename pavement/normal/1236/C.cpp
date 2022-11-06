#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, idx = 0;
	scanf("%d", &n);
	int nums[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			nums[i][j] = i * n + j + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0) printf("%d ", nums[j][idx]);
			else printf("%d ", nums[j][n - idx - 1]);
		}
		printf("\n");
		idx++;
	}
}