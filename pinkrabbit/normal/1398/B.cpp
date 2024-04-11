#include <cstdio>
#include <algorithm>

char s[105];
int a[105], n;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		n = 0;
		scanf("%s", s + 1);
		int len = 0;
		for (int i = 1; s[i]; ++i) {
			if (s[i] == '1') ++len;
			else a[++n] = len, len = 0;
		}
		a[++n] = len;
		std::sort(a + 1, a + n + 1);
		int x = 0;
		for (int i = n; i >= 1; i -= 2) x += a[i];
		printf("%d\n", x);
	}
	return 0;
}