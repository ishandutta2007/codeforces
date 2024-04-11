#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int q, m;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &m);
		printf("%d\n", upper_bound(a, a + n, m) - a);
	}
}