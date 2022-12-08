#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>

using namespace std;

typedef long long ll;
typedef double ld;

int solve();

#define TASK "queuemin2"

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

const int dd = (int)2e5 + 7;

vector<vector<int> > E;
int used[dd];
int cur = 0, cnt = 0;

void dfs(int v) {
	used[v] = 1;
	cnt++;
	cur += (int)E[v].size();
	for (int to : E[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int solve() {
	int n, m;
	scanf("%d %d", &n, &m);

	E.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		E[a - 1].push_back(b - 1);
		E[b - 1].push_back(a - 1);
	}

	int ok = 1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cur = 0, cnt = 0;
			dfs(i);

			if (1ll * cnt * (cnt - 1) != cur) ok = 0;
		}
	}
	puts(ok ? "YES" : "NO");
	return 0;
}