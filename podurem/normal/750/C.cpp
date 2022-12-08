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

const int dd = (int)1e6 + 7;
const int inf = (int)1e9 + 7;

int l = -inf, r = inf;

void upd(int ln, int rn) {
	if (min(r, rn) < max(l, ln))
		exit(0 * puts("Impossible"));
	l = max(l, ln);
	r = min(r, rn);
}

int solve() {
	int n, c, d;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &c, &d);
		if (d == 1)
			upd(1900, inf);
		else
			upd(-inf, 1899);
		if (l != -inf)
			l += c;
		if (r != inf)
			r += c;
	}
	if (r == inf)
		return 0 * puts("Infinity");
	printf("%d", r);
	return 0;
}