#include <bits/stdc++.h>
using namespace std;

int N, Q, a[1000005];
bool flag = 0;
long long eo = 0, oo = 0;

int main() {
	scanf("%d%d", &N, &Q);
	while (Q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int p;
			scanf("%d", &p);
			eo += p;
			oo += p;
			if (p % 2 != 0) flag = !flag;
		} else {
			if (!flag) {
				eo++;
				oo--;
			} else {
				oo++;
				eo--;
			}
			flag = !flag;
		}
	}
	//printf("e: %d, o: %d\n", eo, oo);
	for (long long i = 0; i < N; i++) {
		if (i % 2 == 0) a[((i + eo) % N + N) % N] = i;
		else a[((i + oo) % N + N) % N] = i;
	}
	for (long long i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%d", a[i] + 1);
	}
	printf("\n");
}