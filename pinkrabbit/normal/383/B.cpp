#include <cstdio>
#include <algorithm>

const int MK = 100005;

int T, N, M, K;
int px[MK], py[MK], pp[MK];
inline bool cmp(int i, int j) {
	if (px[i] == px[j]) return py[i] < py[j];
	return px[i] < px[j];
}

int lb[MK], rb[MK], tp;
int tlb[MK], trb[MK], ttp;
int yp[MK], c;

int main() {
    T = 1;
	while (T--) {
		scanf("%d%d", &N, &K), M = N;
		for (int i = 1; i <= K; ++i) scanf("%d%d", &px[i], &py[i]), pp[i] = i;
		std::sort(pp + 1, pp + K + 1, cmp);
		int lstr = 0;
		lb[tp = 1] = rb[1] = 1;
		for (int id = 1; id <= K; ++id) {
			yp[++c] = py[pp[id]];
			if (id != K && px[pp[id]] == px[pp[id + 1]]) continue;
			int nowr = px[pp[id]];
			if (nowr - lstr >= 2) rb[tp = 1] = M;
			yp[++c] = M + 1;
			int j = 0; ttp = 0;
			for (int i = 1; i <= c; ++i) {
				while (j < tp && rb[j + 1] <= yp[i - 1]) ++j;
				if (j < tp && std::max(lb[j + 1], yp[i - 1] + 1) < yp[i])
					tlb[++ttp] = std::max(lb[j + 1], yp[i - 1] + 1),
					trb[ttp] = yp[i] - 1;
			}
			for (int i = 1; i <= ttp; ++i)
				lb[i] = tlb[i], rb[i] = trb[i];
			tp = ttp;
			lstr = nowr, c = 0;
			if (!tp) break;
		}
		if (!tp) { puts("-1"); continue; }
		if (lstr == N && rb[tp] != M) puts("-1");
		else printf("%d\n", N + M - 2);
	}
	return 0;
}