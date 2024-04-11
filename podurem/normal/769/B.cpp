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

using namespace std;

typedef long long ll;
typedef int ld;

#define TASK "divisible"

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)1e2 + 7;
const int inf = (int)1e9 + 7;

pair<int, int> A[dd];
int ans[dd];

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i].first), A[i].second = i;

	sort(A + 1, A + n);
	reverse(A + 1, A + n);
	for (int i = 1; i < n; ++i) {
		int ok = 1;
		for (int j = 0; j < i; ++j) if (A[j].first) {
			ans[i] = A[j].second, A[j].first--, ok = 0;
			break;
		}
		if (ok)
			return 0 * puts("-1");
	}

	printf("%d\n", n - 1);
	for (int i = 1; i < n; ++i)
		printf("%d %d\n", ans[i] + 1, A[i].second + 1);
	return 0;
}