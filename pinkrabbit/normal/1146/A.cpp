#include <cstdio>
#include <cstring>

const int MN = 55;

char s[MN];
int N, cnt;

int main() {
	scanf("%s", s + 1), N = strlen(s + 1);
	for (int i = 1; i <= N; ++i)
		if (s[i] == 'a') ++cnt;
	printf("%d\n", 2 * cnt > N ? N : 2 * cnt - 1);
	return 0;
}

// lg