#include <cstdio>
#include <cstring>

const int MN = 100005;

char t[MN], s[MN];
int N, K;

int main() {
	scanf("%s", t + 1), N = strlen(t + 1);
	for (int i = 1; i <= N; ++i)
		if (t[i] != 'a') s[++K] = t[i];
	if (K & 1) return puts(":("), 0;
	for (int i = 1; i <= K / 2; ++i)
		if (s[i] != s[i + K / 2]) return puts(":("), 0;
	for (int i = 1; i <= K / 2; ++i)
		if (t[N - i + 1] == 'a') return puts(":("), 0;
	for (int i = 1; i <= N - K / 2; ++i)
		printf("%c", t[i]);
	return 0;
}

// lg