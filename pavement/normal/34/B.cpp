#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, c = 0;
	scanf("%d%d", &n, &m);
	int arr[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n && m; i++, m--) {
		if (arr[i] >= 0) break;
		c -= arr[i];
	}
	printf("%d\n", c);
}