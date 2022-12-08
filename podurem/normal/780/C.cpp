#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef double ld;

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	solve();
	return  0;
}

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

vector<int> G[dd];
int c[dd];

void dfs(int v, int p = -1) {
	int C1 = c[v];
	int C2 = (p == -1 ? -1 : c[p]);
	int C = 1;
	for (int i = 0; i < (int)G[v].size(); ++i) if (G[v][i] != p) {
		while (C == C1 || C == C2) ++C;
		c[G[v][i]] = C;
		++C;
		dfs(G[v][i], v);
	}
}

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	c[0] = 1;
	dfs(0);
	int O = 0;
	for (int i = 0; i < n; ++i)
		O = max(O, c[i]);

	printf("%d\n", O);
	for (int i = 0; i < n; ++i)
		printf("%d ", c[i]);
	return 0;
}