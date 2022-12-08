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

int dp[dd], A[dd];
int T[4 * dd], psh[4 * dd];

void push(int v) {
	T[v] += psh[v];
	if (v * 2 + 1 < 4 * dd) {
		psh[v * 2] += psh[v];
		psh[v * 2 + 1] += psh[v];
	}
	psh[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int val) {
	if (tl == l && tr == r) {
		psh[v] += val;
		push(v);
	} else {
		push(v);
		int tm = (tl + tr) / 2;
		if (r <= tm)
			upd(v * 2, tl, tm, l, r, val);
		else if (l > tm)
			upd(v * 2 + 1, tm + 1, tr, l, r, val);
		else
			upd(v * 2, tl, tm, l, tm, val), upd(v * 2 + 1, tm + 1, tr, tm + 1, r, val);
		push(v * 2 + 1), push(v);
		T[v] = max(T[v * 2], T[v * 2 + 1]);
	}
}

int X[dd];

int get(int v, int tl, int tr) {
	push(v);
	if (tl == tr)
		return X[tl];
	else {
		int tm = (tl + tr) / 2;
		push(v * 2), push(v * 2 + 1);
		if (T[v * 2 + 1] > 0)
			return get(v * 2 + 1, tm + 1, tr);
		return get(v * 2, tl, tm);
	}
}

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int p, t;
		scanf("%d %d", &p, &t);
		--p;
		if (t == 0)
			upd(1, 0, n - 1, 0, p, -1);
		else {
			scanf("%d", &X[p]);
			upd(1, 0, n - 1, 0, p, 1);
		}

		push(1);
		if (T[1] <= 0) {
			puts("-1");
			continue;
		}
		printf("%d\n", get(1, 0, n - 1));
	}
	return 0;
}