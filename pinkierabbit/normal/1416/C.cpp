#include <cstdio>

typedef long long LL;
const int MN = 300005, MS = 10000005;

int ch[MS][2], cnt;
LL v[MS][2], s[MS][2];
int N, A[MN];

LL sum[30][2];
void DFS(int u, int d) {
	if (d < 0) return ;
	sum[d][0] += s[u][0];
	sum[d][1] += s[u][1];
	if (ch[u][0]) DFS(ch[u][0], d - 1);
	if (ch[u][1]) DFS(ch[u][1], d - 1);
}

int main() {
	scanf("%d", &N), cnt = 1;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		int now = 1;
		for (int j = 29; j >= 0; --j) {
			int k = A[i] >> j & 1;
			++v[now][k], s[now][k] += v[now][k ^ 1];
			if (!ch[now][k]) ch[now][k] = ++cnt;
			now = ch[now][k];
		}
	}
	DFS(1, 29);
	LL Ans1 = 0;
	int Ans2 = 0;
	for (int j = 29; j >= 0; --j)
		if (sum[j][0] <= sum[j][1])
			Ans1 += sum[j][0];
		else
			Ans1 += sum[j][1],
			Ans2 |= 1 << j;
	printf("%lld %d\n", Ans1, Ans2);
	return 0;
}