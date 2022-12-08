#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <cassert>

using namespace std;

typedef long long ll;
typedef ll ld;

#define TASK "divisible"

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

vector<int> G[dd], ans;
int used[dd], O[dd];

void dfs(int v) {
	used[v] = 1;
	for (int to : G[v]) {
		if (used[to] == 1) exit(0 * puts("-1"));
		if (!used[to]) dfs(to);
	}
	ans.push_back(v);
	used[v] = 2;
}

int solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &O[i]);

	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; ++j) {
			int x;
			scanf("%d", &x);
			G[i].push_back(x - 1);
		}
	}

	for (int j = 0; j < k; ++j) if (!used[O[j] - 1])
		dfs(O[j] - 1);

	printf("%d\n", (int)ans.size());
	for (int i : ans)
		printf("%d ", i + 1);
	return 0;
}