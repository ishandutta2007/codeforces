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

const int dd = (int)3e4 + 7;
const int inf = (int)1e9 + 7;

int solve() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	--k;
	int L = k / (2 * m);
	printf("%d ", L + 1);
	k -= L * (2 * m);
	L = k / 2;
	printf("%d ", L + 1);
	printf(k & 1 ? "R" : "L");
	return 0;
}