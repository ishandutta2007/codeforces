#include <cstdio>

const int MN = 1000005, MP = MN;

bool ip[MN];
int pc, p[MP];
int Ans[MN];

void Init(int N) {
	for (int i = 2; i <= N; ++i) {
		if (!ip[i]) p[++pc] = i;
		for (int j = 1, k; j <= pc; ++j) {
			if ((k = p[j] * i) > N) break;
			ip[k] = 1;
			if (i % p[j] == 0) break;
		}
	}
	++Ans[1];
	for (int i = 1; i <= pc; ++i) {
		++Ans[p[i]];
		if (p[i] <= N / p[i]) --Ans[p[i] * p[i]];
	}
	for (int i = 2; i <= N; ++i) Ans[i] += Ans[i - 1];
}

int main() {
	Init(1000000);
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", Ans[N]);
	}
	return 0;
}