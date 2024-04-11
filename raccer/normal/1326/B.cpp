#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main () {
	int n; scanf("%d", &n);
	int maxj = 0;
	for (int i = 0; i < n; i++) {
		int b; scanf("%d", &b);
		a[i] = maxj + b, maxj = max(maxj, a[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}