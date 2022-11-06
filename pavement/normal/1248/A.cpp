#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m, tmp;
	scanf("%d", &t);
	while (t--) {
		long long ins = 0;
		scanf("%d", &n);
		int e = 0, o = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			if (tmp % 2 == 0) e++;
			else o++;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &tmp);
			if (tmp % 2 == 0) ins += e;
			else ins += o;
		}
		printf("%lld\n", ins);
	}
}