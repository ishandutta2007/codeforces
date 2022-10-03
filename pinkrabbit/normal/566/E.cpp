#include <cstdio>
#include <bitset>

const int MN = 1005;

int N, Cnt, k[MN];
std::bitset<1001> b[MN], a[MN], tmp, il;

int main() {
	scanf("%d", &N);
	if (N == 2) return puts("1 2"), 0;
	for (int i = 1, x; i <= N; ++i) {
		scanf("%d", &k[i]), Cnt += k[i] == N;
		for (int j = 1; j <= k[i]; ++j) scanf("%d", &x), b[i][x] = 1;
	}
	if (Cnt == N) {
		for (int i = 2; i <= N; ++i) printf("1 %d\n", i);
		return 0;
	}
	if (Cnt == 2) {
		int u = 0, v = 0, x = 0;
		for (int i = 1; i <= N; ++i) tmp[i] = 1;
		for (int i = 1; i <= N; ++i)
			if (k[i] != N) x = i, tmp &= b[i];
		for (int i = 1; i <= N; ++i) if (tmp[i]) (u ? v : u) = i;
		printf("%d %d\n", u, v);
		for (int i = 1; i <= N; ++i)
			if (i != u && i != v) printf("%d %d\n", i, b[x][i] ? u : v);
		return 0;
	}
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j < i; ++j) {
			tmp = b[i] & b[j];
			if ((int)tmp.count() != 2) continue;
			int u = tmp._Find_first();
			int v = tmp._Find_next(u);
			if (!a[u][v]) {
				printf("%d %d\n", u, v);
				il[u] = il[v] = 1;
				a[v][u] = a[u][v] = 1;
			}
		}
	for (int i = 1; i <= N; ++i) if (il[i]) a[i][i] = 1;
	k[0] = N + 1;
	for (int i = 1; i <= N; ++i) if (!il[i]) {
		int x = 0;
		for (int j = 1; j <= N; ++j) if (b[j][i] && k[j] < k[x]) x = j;
		tmp = b[x] & il;
		for (int j = 1; j <= N; ++j) if (il[j] && tmp == a[j]) { printf("%d %d\n", j, i); break; }
	}
	return 0;
}