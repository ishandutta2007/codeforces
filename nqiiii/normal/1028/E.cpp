#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int n, b[maxn + 10], id;
long long a[maxn + 10];

int pre(int p) {
	return p == 1 ? n : p - 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i)
		if (b[pre(i)] < b[i]) {
			id = i; break;
		}
	if (!id) {
		if (b[1]) printf("NO");
		else {
			printf("YES\n");
			for (int i = 1; i <= n; ++i) printf("1 ");
		}
		return 0;
	}
	a[id] = b[id];
	for (int i = 1, t = id; i < n; ++i, t = pre(t)) {
		a[pre(t)] = b[pre(t)] + (1000000000 / a[t] + 1) * a[t];
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) printf("%lld ", a[i]);
}