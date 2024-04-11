#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TASK "cinema"

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

const int dd = (int)5e2 + 7;
const int INF = (int)1e9 + 7;

int A[dd];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += max(0, k - A[i] - A[i - 1]);
		A[i] += max(0, k - A[i] - A[i - 1]);
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) {
		printf("%d ", A[i]);
	}
	return 0;
}