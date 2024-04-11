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

const int maxn = 1e6 + 10;

int n, m;
char a[maxn], b[maxn];

int main() {
	scanf("%d%s%s", &n, a, b);
	for (int i = 0; i < n - 1; ++i) if(a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]) { ++m, swap(a[i], a[i + 1]), ++i; }
	for (int i = 0; i < n; ++i) if(a[i] != b[i]) ++m;
	printf("%d\n", m);
	return 0;
}