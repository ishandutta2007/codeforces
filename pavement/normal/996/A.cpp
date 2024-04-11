#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[] = {1, 5, 10, 20, 100}, c = 0;
	scanf("%d", &n);
	for (int i = 4; i >= 0; i--) {
		int amt = n / a[i];
		c += amt;
		n -= amt * a[i];
	}
	printf("%d\n", c);
}