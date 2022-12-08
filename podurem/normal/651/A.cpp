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
	solve();
}

const int dd = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

int solve() {
	int a1, a2, ans = 0;
	scanf("%d %d", &a1, &a2);
	while (a1 > 0 && a2 > 0) {
		if (a1 < a2)
			a1++, a2 -= 2;
		else
			a2++, a1 -= 2;
		++ans;
	}
	ans += min(a1, a2);
	printf("%d", ans);
	return 0;
}