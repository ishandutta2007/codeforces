#include <cstdio>

int G[200][200];
int col[200], row[200];
int ans = -1, ansc[200], ansr[200];

int main () {
	int N, M;
	scanf ("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf ("%d", &G[i][j]);
	for (int i = 0; i <= G[0][0]; ++i) {
		col[0] = i;
		row[0] = G[0][0] - i;
		int cur = col[0] + row[0];
		for (int j = 1; j < N; ++j) {
			col[j] = G[j][0] - row[0];
			if (col[j] < 0) goto nextTry;
			cur += col[j];
		}
		for (int j = 1; j < M; ++j) {
			row[j] = G[0][j] - col[0];
			if (row[j] < 0) goto nextTry;
			cur += row[j];
		}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (col[i] + row[j] != G[i][j]) goto nextTry;
		if (ans == -1 || ans > cur) {
			ans = cur;
			for (int i = 0; i < N; ++i)
				ansc[i] = col[i];
			for (int i = 0; i < M; ++i)
				ansr[i] = row[i];
		}
		nextTry:;
	}
	printf ("%d\n", ans);
	if (ans >= 0) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < ansc[i]; ++j)
				printf ("row %d\n", i + 1);
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < ansr[i]; ++j)
				printf ("col %d\n", i + 1);
	}
}