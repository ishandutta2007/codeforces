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
typedef double ld;

#define TASK "split"
#define err(...) fprintf(stderr, __VA_ARGS__)

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".dat", "r", stdin), freopen(TASK".sol", "w", stdout);
#endif
	return solve();
}

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

int used[dd], p[dd], b[dd];

void dfs(int v) {
	used[v] = 1;
	if (!used[p[v]])
		dfs(p[v]);
}

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]), --p[i];
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);

	int ans = 0;
	for (int i = 0; i < n; ++i) if (!used[i]) {
		++ans;
		dfs(i);
	}

	if (ans == 1) ans = 0;

	int cur = 0;
	for (int i = 0; i < n; ++i)
		cur += b[i];

	if (cur % 2 == 0) ++ans;
	printf("%d", ans);
	return 0;
}