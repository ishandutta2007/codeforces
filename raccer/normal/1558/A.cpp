#include <bits/stdc++.h>
using namespace std;

int vis[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b; scanf("%d%d", &a, &b);
		for (int i = 0; i <= a + b; i++) {
			vis[i] = 0;
		}
		int n = a + b, A = n + 1 >> 1, B = n >> 1;
		for (int i = 0; i <= A; i++) {
			if (i <= a && A - i <= b) vis[A - i + a - i] = 1;
		}
		swap(A, B);
		for (int i = 0; i <= A; i++) {
			if (i <= a && A - i <= b) vis[A - i + a - i] = 1;
		}
		int tot = 0;
		for (int i = 0; i <= n; i++) {
			if (vis[i]) tot++;
		}
		printf("%d\n", tot);
		for (int i = 0; i <= n; i++) {
			if (vis[i]) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}