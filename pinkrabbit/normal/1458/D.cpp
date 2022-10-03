#include <cstdio>
#include <cstring>

const int MN = 500005;

int N;
char s[MN];
int _buk[MN * 2], *buk = _buk + MN;

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%s", s + 1);
		N = strlen(s + 1);
		int x = 0;
		for (int i = 1; i <= N; ++i) {
			if (s[i] == '1') --x;
			++buk[x];
			if (s[i] == '0') ++x;
		}
		x = 0;
		for (int i = 1; i <= N; ++i) {
			if (buk[x] && !(buk[x] == 1 && buk[x - 1])) printf("0"), --buk[x++];
			else printf("1"), --buk[--x];
		}
		puts("");
	}
	return 0;
}