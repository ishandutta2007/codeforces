#include <cstdio>

typedef long long LL;
const int Mod = 1000000009;
const int MN = 300005;
const int MS = 1048576;

int N, Q, Fib[MN];
inline int fib(int i) {
	if (i >= 0) return Fib[i];
	else if (i & 1) return Fib[-i];
	else return (Mod - Fib[-i]) % Mod;
}
inline int fs(int l, int r) {
	return (fib(r + 2) - fib(l + 1) + Mod) % Mod;
}

int lb[MS], rb[MS], sum[MS], tg1[MS], tg2[MS];
void Build(int i, int l, int r) {
	lb[i] = l, rb[i] = r;
	if (l == r) return void(scanf("%d", &sum[i]));
	Build(i << 1, l, (l + r) >> 1);
	Build(i << 1 | 1, ((l + r) >> 1) + 1, r);
	sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % Mod;
}
inline void P(int i, int x, int y) {
	sum[i] = (sum[i] + (LL)x * fs(lb[i], rb[i]) + (LL)y * fs(lb[i] - 1, rb[i] - 1)) % Mod;
	tg1[i] = (tg1[i] + x) % Mod, tg2[i] = (tg2[i] + y) % Mod;
}
inline void PushDown(int i) {
	if (tg1[i] || tg2[i]) {
		P(i << 1, tg1[i], tg2[i]);
		P(i << 1 | 1, tg1[i], tg2[i]);
		tg1[i] = tg2[i] = 0;
	}
}
void Mdf(int i, int a, int b) {
	if (rb[i] < a || b < lb[i]) return ;
	if (a <= lb[i] && rb[i] <= b) return P(i, fib(2 - a), fib(1 - a));
	PushDown(i);
	Mdf(i << 1, a, b), Mdf(i << 1 | 1, a, b);
	sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % Mod;
}
int Qur(int i, int a, int b) {
	if (rb[i] < a || b < lb[i]) return 0;
	if (a <= lb[i] && rb[i] <= b) return sum[i];
	PushDown(i);
	return (Qur(i << 1, a, b) + Qur(i << 1 | 1, a, b)) % Mod;
}

int main() {
	scanf("%d%d", &N, &Q);
	Fib[0] = 0, Fib[1] = 1;
	for (int i = 2; i <= N + 2; ++i) Fib[i] = (Fib[i - 1] + Fib[i - 2]) % Mod;
	Build(1, 1, N);
	while (Q--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) Mdf(1, x, y);
		else printf("%d\n", Qur(1, x, y));
	}
	return 0;
}