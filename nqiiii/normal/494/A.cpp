#include <bits/stdc++.h>
using namespace std;
char s[121323];
int n, lst, tot, cnt;
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '#') {
			++cnt;
			lst = i;
		}
		if (s[i] == '(') ++tot;
		if (s[i] == ')') --tot;
	}
	if (tot < cnt) {
		printf("-1"); return 0;
	}
	vector<int> ans;
	int now = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') ++now;
		if (s[i] == ')') --now;
		if (s[i] == '#') {
			if (i == lst) {
				now -= (tot - cnt + 1);
				ans.push_back(tot - cnt + 1);
			} else {
				--now;
				ans.push_back(1);
			}
		}
		if (now < 0) {
			printf("-1"); return 0;
		}
	}
	assert(now == 0);
	for (auto i: ans) printf("%d\n", i);
}