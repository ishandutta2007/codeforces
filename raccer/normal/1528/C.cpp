#include <bits/stdc++.h>
using namespace std;

vector <int> G1[300010], G2[300010];
int id[300010], sz[300010], num[300010], TOT, ans;
set <int> S;

void GetId(int x, int last) {
	id[x] = ++TOT, num[TOT] = x, sz[x] = 1;
	for (auto v : G2[x]) {
		if (v == last) continue;
		GetId(v, x), sz[x] += sz[v];
	}
}

void GetAns(int x, int last) {
	set <int> :: iterator it = S.lower_bound(id[x]);
	int add = -1, era = -1;
	if (it != S.end() && id[x] + sz[x] > *it) goto NXT;
	if (it != S.begin()) {
		it--;
		if (*it + sz[num[*it]] > id[x]) {
			era = *it, add = id[x];
			S.erase(era), S.insert(add);
			goto NXT;
		}
	}
	add = id[x], S.insert(add);
	NXT:;
	ans = max(ans, (int)S.size());
	for (auto v : G1[x]) {
		if (v == last) continue;
		GetAns(v, x);
	}
	if (add != -1) S.erase(add);
	if (era != -1) S.insert(era);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		TOT = 0; for (int i = 1; i <= n; i++) G1[i].clear(), G2[i].clear();
		for (int i = 2; i <= n; i++) {
			int x; scanf("%d", &x);
			G1[x].push_back(i);
		}
		for (int i = 2; i <= n; i++) {
			int x; scanf("%d", &x);
			G2[x].push_back(i);
		}
		GetId(1, 1), ans = 0, GetAns(1, 1);
		printf("%d\n", ans);
	}
	return 0;
}