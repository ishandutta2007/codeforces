#include <bits/stdc++.h>

int a[110000];

int main () {
	int N;
	scanf ("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf ("%d%d", &u, &v);
		++a[u], ++a[v];
	}
	for (int i = 1; i <= N; ++i) if (a[i] == 2) { puts ("NO"); return 0; }
	puts ("YES");
}