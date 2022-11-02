#include <stdio.h>
#include <algorithm>
int n, a[200000];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0, j = n - 1; i < j; i += 2, j -= 2) std::swap(a[i], a[j]);
	for(int i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}