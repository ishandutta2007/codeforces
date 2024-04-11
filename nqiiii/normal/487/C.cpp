#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, inv[maxn + 10];

bool isprm(int v) {
	for (int i = 2; i * i <= v; ++i)
		if (v % i == 0) return 0;
	return 1;
}

int main() {
	scanf("%d", &n);
	if (n == 1) printf("YES\n1");
	else if (n == 4) printf("YES\n1\n3\n2\n4");
	else if (isprm(n)) {
		printf("YES\n");
		inv[0] = 1;
		for (int i = 1; i <= n; ++i) {
			inv[i] = i == 1 ? 1 : (n - 1ll * n / i * inv[n % i] % n);
			printf("%lld\n", i == n ? n : 1ll * i * inv[i - 1] % n);
		}
	} else printf("NO");
}