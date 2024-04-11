//#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>
#include <unordered_map>

using namespace std;

const int maxn = 20010, maxtm = 86500;

int v[maxn];

int tr[maxtm * 5];
int st[maxtm * 5];

void sets(int it, int x) {
	tr[it] += x;
	st[it] += x;
}

void push(int it) {
	if (st[it] != 0) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		st[it] = 0;
	}
}

void change(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		sets(it, 1);
	} else {
		push(it);
		int m = (l + r) / 2;

		if (rm <= m) {
			change(2 * it, l, m, lm, rm);
		} else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm);
		} else {
			change(2 * it, l, m, lm, m);
			change(2 * it + 1, m + 1, r, m + 1, rm);
		}

		tr[it] = max(tr[2 * it], tr[2 * it + 1]);
	}
}

int search(int it, int l, int r, int pos) {
	if (l == r) {
		return tr[it];
	} else {
		push(it);

		int m = (l + r) / 2;

		if (pos <= m) {
			return search(2 * it, l, m, pos);
		} else {
			return search(2 * it + 1, m + 1, r, pos);
		}
	}
}

int num[maxn];

int main() {
	int n, m, t;

	scanf("%d %d %d", &n, &m, &t);

	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d:%d:%d", &x, &y, &z);
		v[i] = x * 60 * 60 + y * 60 + z;
	}

	int last = 0;

	bool st = false;

	for (int i = 0; i < n; i++) {
		if (search(1, 0, maxtm, v[i]) == m - 1) {
			st = true;
		}

		if (search(1, 0, maxtm, v[i]) != m) {
			last++;
			num[i] = last;
			change(1, 0, maxtm, v[i], v[i] + t - 1);
		} else {
			num[i] = last;
			
			if (v[i] != v[i - 1]) {
				change(1, 0, maxtm, v[i - 1] + t, v[i] + t - 1);
			}
		}
	}

	if (!st) {
		printf("No solution");
	} else {
		printf("%d\n", last);

		for (int i = 0; i < n; i++) {
			printf("%d\n", num[i]);
		}
	}

	return 0;
}