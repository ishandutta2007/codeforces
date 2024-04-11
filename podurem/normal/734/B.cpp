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

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "light"
#define all(v) v.begin(), v.end()

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

int solve() {
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	ll ans = 0;
	int cur = min(min(k2, k5), k6);
	ans += 1ll * cur * 256;
	k2 -= cur, k5 -= cur, k6 -= cur;
	cur = min(k2, k3);
	ans += 1ll * cur * 32;
	cout << ans;
	return 0;
}