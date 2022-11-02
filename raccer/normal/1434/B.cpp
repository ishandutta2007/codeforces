#include <bits/stdc++.h>
using namespace std;

int a[200010], ans[200010];
int st[200010], tp;
set <int> S;

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n + n; i++) {
		char op[5]; scanf("%s", op);
		if (op[0] == '+') a[i] = -1, S.insert(i);
		else scanf("%d", &a[i]);
	}
	a[0] = 0x3f3f3f3f;
	st[tp++] = 0;
	for (int i = 1; i <= n + n; i++) {
		if (a[i] == -1) continue;
		while (tp && a[st[tp - 1]] < a[i]) tp--;
		set <int> :: iterator it = S.upper_bound(st[tp - 1]);
		if (it == S.end() || *it >= i) {
			printf("NO\n");
			return 0;
		}
		ans[*it] = a[i], st[tp++] = i;
		S.erase(it);
	}
	printf("YES\n");
	for (int i = 1; i <= n + n; i++) {
		if (a[i] == -1) printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}