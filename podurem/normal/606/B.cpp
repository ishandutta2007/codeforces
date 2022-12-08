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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"

const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e18 + 7;
const int MOD = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int main() {
	file();
	int x, y, x0, y0;
	scanf("%d%d%d%d", &x, &y, &x0, &y0);
	string s;
	getline(cin, s);
	getline(cin, s);
	vector<vector<bool> > U(x + 1, vector<bool>(y + 1, 0));
	for (int i = 0; i < s.size(); ++i) {
		//cout << x0 << " " << y0 << "\n";
		printf("%d ", !U[x0][y0]);
		U[x0][y0] = 1;
		if (s[i] == 'U') {
			if (x0 - 1 > 0) {
				--x0;
			}
		}
		if (s[i] == 'D') {
			if (x0 + 1 <= x) {
				++x0;
			}
		}
		if (s[i] == 'L') {
			if (y0 - 1 > 0) {
				--y0;
			}
		}
		if (s[i] == 'R') {
			if (y0 + 1 <= y) {
				++y0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < x + 1; ++i) {
		for (int j = 1; j < y + 1; ++j) {
			ans += !U[i][j];
		}
	}
	printf("%d ", ans);
	return 0;
}