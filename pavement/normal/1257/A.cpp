#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, x, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &x, &a, &b);
		if (a > b) swap(a, b);
		int nb = min(n, b + x);
		x = max(0, x - (nb - b));
		int na = max(1, a - x);
		printf("%d\n", nb - na);
	}
}