#include <bits/stdc++.h>
using namespace std;

int a[500010];
int st[500010];
int tmp[500010];
long long ans[500010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int top = 0; long long now = 0;
	st[top++] = 0;
	for (int i = 1; i <= n; i++) {
		while (top && a[st[top - 1]] > a[i]) {
			now -= 1ll * a[st[top - 1]] * (st[top - 1] - st[top - 2]);
			top--;
		}
		st[top++] = i;
		now += 1ll * a[st[top - 1]] * (st[top - 1] - st[top - 2]);
		ans[i] = now;
	}
	top = 0;
	st[top++] = n + 1;
	now = 0;
	for (int i = n; i >= 1; i--) {
		while (top && a[st[top - 1]] > a[i]) {
			now -= 1ll * a[st[top - 1]] * (st[top - 2] - st[top - 1]);
			top--;
		}
		st[top++] = i;
		now += 1ll * a[st[top - 1]] * (st[top - 2] - st[top - 1]);
		ans[i] += now;
	}
	long long res = 0; int pos = -1;
	for (int i = 1; i <= n; i++) {
		if (res < ans[i] - a[i]) {
			res = ans[i] - a[i], pos = i;
		}
	}
	tmp[pos] = a[pos];
	for (int i = pos - 1; i >= 1; i--) {
		tmp[i] = min(tmp[i + 1], a[i]);
	}
	for (int i = pos + 1; i <= n; i++) {
		tmp[i] = min(tmp[i - 1], a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", tmp[i]);
	}
	printf("\n");
	return 0;
}