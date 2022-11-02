#include <bits/stdc++.h>
using namespace std;

char s[200010];
char p[200010], q[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d%s", &n, s);
		int one = 0, zero = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') one++;
			else zero++;
		}
		int s1 = 0, s2 = 0;
		int cur = 0, tmp = 0;
		if (one & 1) {
			printf("NO\n");
			goto END;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				if (cur < one / 2) p[i] = q[i] = '(';
				else p[i] = q[i] = ')';
				cur++;
			} else {
				if (tmp & 1) p[i] = '(', q[i] = ')';
				else p[i] = ')', q[i] = '(';
				tmp++;
			}
		}
		for (int i = 0; i < n; i++) {
			s1 += p[i] == '(' ? 1 : -1;
			s2 += q[i] == '(' ? 1 : -1;
			if (s1 < 0 || s2 < 0) {
				printf("NO\n");
				goto END;
			}
		}
		p[n] = q[n] = 0;
		if (s1 != 0 || s2 != 0) printf("NO\n");
		else printf("YES\n%s\n%s\n", p, q);
		END:;
	}
	return 0;
}