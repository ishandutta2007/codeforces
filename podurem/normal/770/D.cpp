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
typedef ll ld;

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

const int dd = (int)4e2 + 7;
const int inf = (int)1e9 + 7;

char ans[dd][dd];
int mx;

void ris(int x, int y) {
	for (int i = y + 1; i <= mx - y; ++i)
		ans[i][x] = '|';
	ans[y][x] = ans[mx - y + 1][x] = '+';
}

int solve() {
	string s;
	cin >> s >> s;
	int cur = 0;
	for (char c : s) {
		cur += (c == '[' ? 1 : -1);
		if (cur > mx) mx = cur;
	}
	mx = 2 * mx - 1;
	for (int i = 0; i < dd; ++i)
		fill(ans[i], ans[i] + dd, ' ');

	int cnt = 0;
	cur = 0;
	for (int i = 0; i < (int)s.size(); ++i, ++cnt) {
		if (i && s[i - 1] == '[' && s[i] == ']')
			cnt += 3;
		cur += (s[i] == '[' ? 1 : -1);
		ris(cnt, cur - (s[i] == '['));
		if (s[i] == '[')
			ans[cur - 1][cnt + 1] = ans[mx + 2 - cur][cnt + 1] = '-';
		else
			ans[cur][cnt - 1] = ans[mx + 1 - cur][cnt - 1] = '-';
	}

	for (int i = 0; i < mx + 2; ++i) {
		for (int j = 0; j < cnt; ++j)
			printf("%c", ans[i][j]);
		puts("");
	}
	return 0;
}