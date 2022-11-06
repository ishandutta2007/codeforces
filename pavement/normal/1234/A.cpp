#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		int s = 0, tmp;
		for (int i = 0; i < n; i++) scanf("%d", &tmp), s += tmp;
		printf("%d\n", (s / n) + (s % n != 0));
	}
}