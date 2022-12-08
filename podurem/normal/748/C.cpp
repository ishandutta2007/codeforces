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
	int n;
	string s;
	cin >> n >> s;
	int a = 0, b = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			if (a < 0) {
				ans++;
				a = 0, b = 0;
			}
			a++;
		} else if (s[i] == 'L') {
			if (a > 0) {
				ans++;
				a = 0, b = 0;
			}
			a--;
		} else if (s[i] == 'U') {
			if (b < 0) {
				ans++;
				a = 0, b = 0;
			}
			b++;
		} else {
			if (b > 0) {
				ans++;
				a = 0, b = 0;
			}
			b--;
		}
	}
	if (a != 0 || b != 0) ans++;
	printf("%d", ans);
	return 0;
}