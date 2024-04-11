#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int T, n, u, v;
int a[maxn + 10];


bool allsame() {
	for (int i = 2; i <= n; ++i)
		if (a[i] != a[i - 1]) return 0;
	printf("%d\n", v + min(u, v));
	return 1;
}

bool conneted() {
	for (int i = 2; i <= n; ++i)
		if (abs(a[i] - a[i - 1]) > 1) return 0;
	printf("%d\n", min(u, v));
	return 1;
}


int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &u, &v);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		if (allsame()) continue;
		if (conneted()) continue;
		printf("0\n");
	}
}