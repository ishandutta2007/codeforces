#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, c = 0;
	scanf("%d%d", &n, &k);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int lowerbound = a[k - 1];
	for (int i : a) {
		if (i >= lowerbound && i > 0) {
			c++;
		}
	}
	printf("%d", c);
}