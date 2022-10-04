#include <cstdio>
#include <cstring>

const int MN = 500005;

int N, M, c0, c1;
char s[MN], t[MN];
int p[MN];

int main() {
	scanf("%s%s", s + 1, t + 1);
	N = strlen(s + 1), M = strlen(t + 1);
	for (int i = 1; i <= N; ++i)
		if (s[i] == '0') ++c0;
		else ++c1;
	int k = 0;
	for (int i = 2; i <= M; ++i) {
		while (k && t[k + 1] != t[i]) k = p[k];
		if (t[k + 1] == t[i]) p[i] = ++k;
	}
	k = 0;
	for (int i = 1; i <= N; ++i) {
		int r = t[k + 1] - '0';
		int q = r ? c1 ? 1 : 0 : c0 ? 0 : 1;
		if (q == r) if (++k == M) k = p[M];
		--(q ? c1 : c0);
		printf("%d", q);
	}
	return 0;
}