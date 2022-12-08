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

int solve() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		dp[i] = dp[i - 1] + 20;
		if (i > 1) {
			int Y = A[i] - 89;
			int ind = lower_bound(A + 1, A + i, Y) - A;
			dp[i] = min(dp[i], dp[ind - 1] + 50);

			Y = A[i] - 1439;
			ind = lower_bound(A + 1, A + i, Y) - A;
			dp[i] = min(dp[i], dp[ind - 1] + 120);
		}
		printf("%d\n", dp[i] - dp[i - 1]);
	}
	return 0;
}