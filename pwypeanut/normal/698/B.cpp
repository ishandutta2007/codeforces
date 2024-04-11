#include <bits/stdc++.h>
using namespace std;

int N, a[200005], p[200005], oria[200005];

int fp(int x) {
	if (p[x] == x) return x;
	else return p[x] = fp(p[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	if (x == y) return;
	else p[x] = y;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= N; i++) oria[i] = a[i];
	int root = -1;
	for (int i = 1; i <= N; i++) if (a[i] == i) root = i;
	if (root == -1) {
		for (int i = 1; i <= N; i++) p[i] = i;
		for (int i = 1; i <= N; i++) {
			if (fp(i) == fp(a[i])) {
				root = i;
				a[i] = i;
				break;
			} else merge(i, a[i]);
		}
	}
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 1; i <= N; i++) {
		if (i == root) continue;
		if (fp(i) == fp(a[i])) {
			a[i] = root;
			merge(a[i], root);
		} else merge(i, a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) if (a[i] != oria[i]) ans++;
	printf("%d\n", ans);
	for (int i = 1; i <= N; i++) {
		if (i != 1) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}