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
	return solve();
}

const int dd = (int)1e3 + 7;
const int inf = (int)1e9 + 7;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Q {
	int x, y;
	int n, h, p;
	bool operator < (Q b) const {
		return x == b.x ? y == b.y ? n == b.n ? h == b.h ? p < b.p : h < b.h : n < b.n : y < b.y : x < b.x;
	}
};

map<Q, bool> used;
int n, t[dd];
int Y[dd][dd];

void go(Q A) {
	if (n == A.p) return;
	Y[A.x][A.y] = 1;
	if (used[A])
		return;
	used[A] = true;
	if (A.h == 0) {
		go({ A.x, A.y, A.n == 0 ? 7 : A.n - 1, t[A.p + 1], A.p + 1 });
		go({ A.x, A.y, A.n == 7 ? 0 : A.n + 1, t[A.p + 1], A.p + 1 });
	} else
		go({ A.x + dx[A.n], A.y + dy[A.n], A.n, A.h - 1, A.p });
}

int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	go({ 400 + dx[0], 400 + dy[0], 0, t[0] - 1, 0 });

	int ans = 0;
	for (int i = 0; i < dd; ++i)
		for (int j = 0; j < dd; ++j)
			ans += Y[i][j];
	printf("%d", ans);
	return 0;
}