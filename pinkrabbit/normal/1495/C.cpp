#include <cstdio>

const int MN = 505;

int N, M;
char S[MN][MN], T[MN][MN];

void Solve() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%s", S[i] + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j)
			T[i][j] = j == 1 || i % 3 == 1 || S[i][j] == 'X' ? 'X' : '.';
		T[i][M + 1] = '\0';
	}
	if (N % 3 == 0) {
		for (int j = 1; j <= M; ++j)
			T[N][j] = 'X';
	}
	if (N % 3 == 2 && S[N][1] == '.') T[N][1] = '.';
	for (int i = 1; i <= N - 1; ++i) if (i % 3 != 1)
		for (int j = 2; j <= M; ++j) if (S[i][j] == 'X') {
			if (N % 3 == 0 && i == N - 1) {
				if (j == 2) T[i][1] = '.';
				else T[i + 1][j - 1] = '.';
			} else if (j == 2) {
				int t = i % 3 ? i : i - 1;
				T[t][1] = T[t + 1][1] = '.';
				T[t][2] = T[t + 1][2] = 'X';
			}
		}
	for (int i = 1; i <= N; ++i) printf("%s\n", T[i] + 1);
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) Solve();
	return 0;
}