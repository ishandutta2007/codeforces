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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "light"

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

const int dd = (int)1e3 + 7;
const int inf = (int)1e9 + 7;

int W[dd], K[dd];
vector<int> G[dd];
int used[dd], iR, Sw, Sk;
vector<pair<int, int> > R[dd];

void dfs(int v) {
	used[v] = 1;
	Sw += W[v], Sk += K[v];
	R[iR].push_back({ W[v], K[v] });
	for (auto to : G[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int dp[2][1007];

inline void uax(int &a, int b) {
	if (a < b) a = b;
}

int solve() {
	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i < n; ++i)
		scanf("%d", &W[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &K[i]);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			Sw = 0, Sk = 0;
			dfs(i);
			R[iR].push_back({ Sw, Sk });
			++iR;
		}
	}

	for (int i = 1; i <= iR; ++i) {
		memset(dp[i & 1], 0, sizeof(int) * 1007);

		for (int j = 0; j < (int)R[i - 1].size(); ++j) {
			for (int ww = R[i - 1][j].first; ww <= w; ++ww) {
				uax(dp[i & 1][ww], dp[(i + 1) & 1][ww - R[i - 1][j].first] + R[i - 1][j].second);
			}
		}
		for (int ww = 0; ww <= w; ++ww)
			uax(dp[i & 1][ww], dp[(i + 1) & 1][ww]);
	}
	int ans = 0;
	for (int i = 0; i <= w; ++i) {
		uax(ans, dp[iR & 1][i]);
	}
	printf("%d", ans);
	return 0;
}