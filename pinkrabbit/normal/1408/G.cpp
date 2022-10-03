#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int MN = 1505;

int N;
int eu[MN * MN / 2], ev[MN * MN / 2];

int pa[MN], siz[MN], edg[MN], f[MN][MN], g[MN];
int fp(int x) { return pa[x] ? pa[x] = fp(pa[x]) : x; }

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int c;
			scanf("%d", &c);
			if (i < j) eu[c] = i, ev[c] = j;
		}
	}
	for (int i = 1; i <= N; ++i) {
		siz[i] = 1;
		edg[i] = 0;
		f[i][1] = 1;
	}
	for (int i = 1; i <= N * (N - 1) / 2; ++i) {
		int x = fp(eu[i]), y = fp(ev[i]);
		if (x != y) {
			if (siz[x] < siz[y]) std::swap(x, y);
			for (int j = 2; j <= siz[x] + siz[y]; ++j) g[j] = 0;
			for (int j = 1; j <= siz[x]; ++j)
				for (int k = 1; k <= siz[y]; ++k)
					g[j + k] = (g[j + k] + (LL)f[x][j] * f[y][k]) % Mod;
			for (int j = 1; j <= siz[x] + siz[y]; ++j) f[x][j] = g[j];
			siz[x] += siz[y];
			edg[x] += edg[y] + 1;
			pa[y] = x;
		} else ++edg[x];
		if (siz[x] * (siz[x] - 1) / 2 == edg[x]) ++f[x][1];
	}
	int rt = fp(1);
	for (int i = 1; i <= N; ++i) printf("%d%c", f[rt][i], " \n"[i == N]);
	return 0;
}