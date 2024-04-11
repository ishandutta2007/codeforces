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

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

int c[dd], d[dd], t = 1, G[dd];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int nok(int a, int b) {
	return a * b / gcd(a, b);
}

void dfs(int v) {
	int to = c[v];
	if (d[to] == 0) {
		d[to] = d[v] + 1;
		dfs(to);
	} else {
		if ((d[v] - d[to]) % 2) {
			int Y = d[v] - d[to] + 1;
			t = nok(t, Y / 2);
		} else {
			int Y = d[v] - d[to] + 1;
			t = nok(t, Y);
		}
	}
}

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
		c[i]--;
		G[c[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (G[i] == 0) {
			return 0 * puts("-1");
		}
	}

	for (int i = 0; i < n; ++i) {
		if (d[i] == 0) {
			d[i] = 1;
			dfs(i);
		}
	}
	printf("%d", t);
	return 0;
}