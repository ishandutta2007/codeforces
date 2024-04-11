#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 100000;
int n, ch[maxN + 10][26], ndCnt, dep[maxN + 10], ans;
bool has[maxN + 10];
char s[maxN + 10];
multiset<int> st[maxN + 10];

void Merge(int x, int y) {
	if (st[x].size() < st[y].size()) st[x].swap(st[y]);
	for (multiset<int>::iterator it = st[y].begin(); it != st[y].end(); ++it)
		st[x].insert(*it);
}

void Dfs(int p) {
	for (int i = 0; i < 26; ++i)
		if (ch[p][i]) {
			dep[ch[p][i]] = dep[p] + 1;
			Dfs(ch[p][i]); Merge(p, ch[p][i]);
		}
	if (has[p]) st[p].insert(dep[p]);
	else if (!st[p].empty()){
		st[p].erase(--st[p].end()); st[p].insert(dep[p]);
	}
}

int main() {
	scanf("%d", &n); has[0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1); int l = strlen(s + 1), t = 0;
		for (int j = 1; j <= l; ++j) {
			if (!ch[t][s[j] - 'a']) ch[t][s[j] - 'a'] = ++ndCnt;
			t = ch[t][s[j] - 'a'];
		}
		has[t] = 1;
	}
	Dfs(0);
	for (multiset<int>::iterator it = st[0].begin(); it != st[0].end(); ++it)
		ans += *it;
	printf("%d", ans);
}