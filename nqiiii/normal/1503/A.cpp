#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int T, n;
char s[maxn + 10];
int a[maxn + 10], b[maxn + 10];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (s[i] == '1') ++cnt;
		if (cnt & 1) {
			puts("NO"); continue;
		}
		for (int i = 1, t = 0; i <= n; ++i)
			if (s[i] == '1') {
				++t;
				if (t <= cnt / 2) a[i] = b[i] = 1;
				else a[i] = b[i] = -1;
			}
		for (int i = 1, t = 1; i <= n; ++i)
			if (s[i] == '0') {
				a[i] = t; b[i] = -t;
				t *= -1;
			}
		int s1 = 0, s2 = 0;
		bool fd = 1;
		for (int i = 1; i <= n; ++i) {
			s1 += a[i]; s2 += b[i];
			if (s1 < 0 || s2 < 0) fd = 0;
		}
		if (s1 != 0 || s2 != 0) fd = 0;
		if (!fd) {
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1) printf("(");
			else printf(")");
		puts("");
		for (int i = 1; i <= n; ++i)
			if (b[i] == 1) printf("(");
			else printf(")");
		puts("");
	}
}