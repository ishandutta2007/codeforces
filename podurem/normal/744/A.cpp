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
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "lasers"

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

const int dd = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

vector<int> G[dd];
int used[dd], K, C[dd], T, GG;

void dfs(int v) {
	GG += (int)G[v].size();
	if (C[v]) T = 1;
	used[v] = 1;
	K++;
	for (auto to : G[v]) if (!used[to])
		dfs(to);
}

int solve() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		C[x - 1] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		G[x].push_back(y), G[y].push_back(x);
	}

	ll ans = 0;
	int H = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			K = T = GG = 0;
			dfs(i);
			GG /= 2;
			ans += 1ll * K * (K - 1) / 2 - GG;
			if (T) H = max(H, K);
		}
	}

	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			K = T = 0;
			dfs(i);
			if (!T) {
				ans += 1ll * K * H;
				H += K;
			}
		}
	}
	cout << ans;

	return 0;
}