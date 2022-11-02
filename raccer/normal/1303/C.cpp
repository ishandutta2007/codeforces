#include <bits/stdc++.h>
using namespace std;

char ans[410];
int vis[26];

int main () {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int now = 200, ll = now, rr = now;
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		ans[now] = s[0], now++, vis[s[0] - 'a'] = 1;
		for (int i = 1; i < s.size(); i++) {
			ans[now] = s[i], ll = min(ll, now), rr = max(rr, now), vis[s[i] - 'a'] = 1;
			if (i + 1 == s.size()) break;
			char tmp = s[i + 1];
			if (ans[now + 1] == tmp) now++;
			else if (ans[now - 1] == tmp) now--;
			else if (ans[now + 1] == 0) {
				if (vis[tmp - 'a']) {
					printf("NO\n");
					goto END;
				}
				now++;
			} else if (ans[now - 1] == 0) {
				if (vis[tmp - 'a']) {
					printf("NO\n");
					goto END;
				}
				now--;
			} else {
				printf("NO\n");
				goto END;
			}
		}
		printf("YES\n");
		for (int i = ll; i <= rr; i++) {
			printf("%c", ans[i]);
		}
		for (int i = 0; i < 26; i++) {
			if (!vis[i]) printf("%c", char(i + 'a'));
		}
		printf("\n");
		END:;
	}
	return 0;
}