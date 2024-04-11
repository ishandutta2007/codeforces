#include <bits/stdc++.h>
using namespace std;

char s[100010];
int tot[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, x; scanf("%d%d", &n, &x);
		scanf("%s", s + 1);
		tot[0] = 0;
		for (int i = 1; i <= n; i++) {
			tot[i] = tot[i - 1] + (s[i] == '0' ? 1 : -1);
		}
		if (tot[n] == 0) {
			for (int i = 1; i <= n; i++) {
				if (tot[i] == x) {
					printf("-1\n");
					goto END;
				}
			}
			printf("0\n");
			continue;
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int d = x - tot[i];
				if (d == 0) {
					ans++;
					continue;
				}
				if (d < 0 && tot[n] > 0 || d > 0 && tot[n] < 0) continue;
				if (abs(d) % abs(tot[n]) == 0) ans++; 
			}
			printf("%d\n", ans + (x == 0 ? 1 : 0));
		}
		END:;
	}
	return 0;
}