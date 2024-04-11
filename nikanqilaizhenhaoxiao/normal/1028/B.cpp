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

int main() {
	int n = 2210, m = n / 2;
	for (int i = 0; i < m; ++i) putchar('9');
	for (int i = 0; i < m - 1; ++i) putchar('0');
	putchar('1');
	putchar(' ');
	for (int i = 0; i < m; ++i) putchar('9');
	putchar('\n');
	return 0;
}