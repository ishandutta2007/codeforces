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

const int dd = (int)5e5 + 7;
const int inf = (int)1e9 + 7;

int solve() {
	int n;
	scanf("%d", &n);
	int ans = 0, x;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		ans += x;
	}
	printf("%d", ans / n);
	return 0;
}