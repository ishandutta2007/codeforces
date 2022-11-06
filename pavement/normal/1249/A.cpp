#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, n;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		int a[n], t = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) == 1) {
				t = 1;
			}
		}
		if (t) printf("2\n");
		else printf("1\n");
	}
}