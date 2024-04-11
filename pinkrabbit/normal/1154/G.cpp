#include <cstdio>

typedef long long LL;
const int MX = 10000000;

int N;
int V[MX + 5];
LL Ans = (LL)MX * MX; int A1, A2;

int main() {
	scanf("%d", &N);
	for (int i = 1, x; i <= N; ++i) {
		scanf("%d", &x);
		if (V[x]) if (Ans > x) Ans = x, A1 = V[x], A2 = i;
		V[x] = i;
	}
	for (int i = 1; i <= MX; ++i) {
		if (Ans <= i) break;
		LL P1 = 0;
		for (int j = i; j <= MX; j += i) {
			if (Ans <= (LL)(P1 ? P1 : j) * j / i) break;
			if (!V[j]) continue;
			if (!P1) P1 = j;
			else {
				if (Ans > P1 * j / i) Ans = P1 * j / i, A1 = V[P1], A2 = V[j];
				break;
			}
		}
	}
	if (A1 > A2) A1 ^= A2 ^= A1 ^= A2;
	printf("%d %d\n", A1, A2);
	return 0;
}