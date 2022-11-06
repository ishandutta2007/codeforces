#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, co[maxn * 2 + 10];
bool now;
char ans[maxn + 10];
map<int, int> mp[maxn * 2 + 10];
set<int> st[2];

void dfs(int p) {
	while (!mp[p].empty()) {
		int e = mp[p].begin() -> first, id = mp[p].begin() -> second;
		mp[p].erase(e); mp[e].erase(p);
		dfs(e); ans[id] = (now ^= 1) ? 'r' : 'b';
	}
}

void calc() {
	for (int i = 1; i <= maxn * 2; ++i)
		dfs(i);
}

void solve() {
	if (st[1].empty()) {
		calc(); return;
	}
	int p = *st[1].begin();
	int q = mp[p].begin() -> first;
	int id = mp[p].begin() -> second;
	st[mp[p].size() & 1].erase(p);
	st[mp[q].size() & 1].erase(q);
	mp[p].erase(q); mp[q].erase(p);
	st[mp[p].size() & 1].insert(p);
	st[mp[q].size() & 1].insert(q);
	solve();
	if (co[q] <= 0) {
		++co[p]; ++co[q]; ans[id] = 'r';
	} else {
		--co[p]; --co[q]; ans[id] = 'b';
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		mp[l][r + maxn] = i;	
		mp[r + maxn][l] = i;
	}
	for (int i = 1; i <= maxn * 2; ++i) {
		st[mp[i].size() & 1].insert(i);
	}
	solve();
	for (int i = 1; i <= n; ++i)
		printf("%c", ans[i]);
}