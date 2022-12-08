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

const int dd = (int)1e6 + 7;
const int inf = (int)1e9 + 7;

int solve() {
	int n, x = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int xx;
		string d;
		cin >> xx >> d;
		if (x == 0 && d[0] != 'S')
			return 0 * puts("NO");
		if (x == 20000 && d[0] != 'N')
			return 0 * puts("NO");
		if (d[0] == 'S')
			x += xx;
		else if (d[0] == 'N')
			x -= xx;
		if (x < 0 || x > 20000)
			return 0 * puts("NO");
	}
	puts(x == 0 ? "YES" : "NO");
	return 0;
}