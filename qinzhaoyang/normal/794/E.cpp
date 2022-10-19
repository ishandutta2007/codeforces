#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n, a[300010], mx0 = 0, mx1 = 0, mx = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), mx = max(mx, a[i]);
	for (int i = 0; i < n - 1; i++) {
		int l = (1 + n - i) / 2, r = (i + 1 + n) / 2;
		if ((n - i) % 2 == 0)
			printf("%d ", mx0 = max(mx0, max(max(a[l], a[l + 1]), max(a[r], a[r + 1]))));
		else
			printf("%d ", mx1 = max(mx1, max(min(a[l], max(a[l - 1], a[l + 1])), min(a[r], max(a[r - 1], a[r + 1])))));
	}
	return printf("%d\n", mx) * 0;
}