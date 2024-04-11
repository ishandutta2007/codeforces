#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef double ld;

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	solve();
	return  0;
}

const int dd = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

int F[dd];

int solve() {
	int n, cur = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i) {
		int x;
		scanf("%d", &x);
		F[x] ^= 1;
		cur += F[x];
		if (F[x] == 0) cur--;
		ans = max(ans, cur);
	}
	printf("%d", ans);
	return 0;
}