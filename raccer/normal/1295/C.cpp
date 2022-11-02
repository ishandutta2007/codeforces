#include <bits/stdc++.h>
using namespace std;

char s[100010], t[100010];
int v1[26], v2[26];
int nxt[100010][26];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s%s", s, t);
		int n = strlen(s), m = strlen(t);
		memset(v1, 0, sizeof(v1)), memset(v2, 0, sizeof(v2));
		for (int i = 0; i < n; i++) {
			v1[s[i] - 'a'] = 1;
		}
		for (int i = 0; i < m; i++) {
			v2[t[i] - 'a'] = 1;
		}
		int now = 0, ans = 1;
		for (int i = 0; i < 26; i++) {
			if (v2[i] && !v1[i]) {
				printf("-1\n");
				goto END;
			}
		}
		for (int i = 0; i < 26; i++) {
			nxt[n][i] = n;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				nxt[i][j] = nxt[i + 1][j];
			}
			nxt[i][s[i] - 'a'] = i;
		}
		for (int i = 0; i < m; i++) {
			if (nxt[now][t[i] - 'a'] == n) now = 0, ans++;
			now = nxt[now][t[i] - 'a'] + 1;
		}
		printf("%d\n", ans);
		END:;
	}
	return 0;
}