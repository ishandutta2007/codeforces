#include <bits/stdc++.h>
using namespace std;

int N, E, p[1005];

int fp(int x) {
	if (p[x] == x) return x;
	else return p[x] = fp(p[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	p[x] = y;
}

int main() {
	scanf("%d%d", &N, &E);
	if (N != E + 1) {
		printf("no\n");
		return 0;
	}
	for (int i = 0; i < N; i++) p[i] = i;
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (fp(a) == fp(b)) {
			printf("no\n");
			return 0;
		}
		merge(a, b);
	}
	printf("yes\n");
}