#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

const int maxn = 120;

char s[maxn][maxn];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(s[i][j] == 'B') {
				int x = i, y = j;
				while(y <= m && s[i][y] == 'B') ++y;
				while(x <= n && s[x][j] == 'B') ++x;
				--x; --y;
				printf("%d %d\n", x + i >> 1, y + j >> 1);
				return 0;
			}
		}
	}
	return 0;
}