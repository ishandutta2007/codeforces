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
	//freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

const int dd = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

int Z[30][dd], iZ = 0, A[30][dd];

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i *= 2) {
		for (int j = 0; j < n; j += 2 * i)
			for (int k = j; k < j + i; ++k) {
				Z[iZ][k] = 1;
			}
		iZ++;
		for (int j = 0; j < n; ++j)
			Z[iZ][j] = !Z[iZ - 1][j];
		iZ++;
	}

	for (int i = 0; i < iZ; ++i) {
		int k = 0;
		for (int j = 0; j < n; ++j)
			k += Z[i][j];
		printf("%d\n", k);
		for (int j = 0; j < n; ++j) if (Z[i][j])
			printf("%d ", j + 1);
		printf("\n");
		fflush(stdout);
		for (int j = 0; j < n; ++j)
			scanf("%d", &A[i][j]);
	}
	printf("-1\n");
	for (int i = 0; i < n; ++i) {
		int Ans = inf;
		for (int j = 0; j < iZ; ++j) if (!Z[j][i])
			Ans = min(Ans, A[j][i]);
		printf("%d ", Ans);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}