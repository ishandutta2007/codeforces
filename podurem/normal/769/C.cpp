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

const int dd = (int)1e3 + 7;
const int inf = (int)1e9 + 7;

string A[dd];
int D[dd][dd], dx[] = { 1, 0, 0, -1 }, dy[] = { 0, -1, 1, 0 }, X[dd * dd], Y[dd * dd], iL, iR, n, m;
char N[] = { 'D', 'L', 'R', 'U' };

bool ss(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

void bfs(int x, int y) {
	iL = 0, iR = 1;
	X[0] = x, Y[0] = y;
	for (int i = 0; i < dd; ++i)
		fill(D[i], D[i] + dd, inf);
	D[x][y] = 0;
	while (iR != iL) {
		int i = X[iL], j = Y[iL++];
		for (int k = 0; k < 4; ++k) {
			int ni = i + dx[k], nj = j + dy[k];
			if (ss(ni, nj) && A[ni][nj] != '*' && D[ni][nj] == inf) {
				D[ni][nj] = D[i][j] + 1;
				X[iR] = ni, Y[iR++] = nj;
			}
		}
	}
}

int solve() {
	int k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	int x, y;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (A[i][j] == 'X') x = i, y = j;

	bfs(x, y);

	string ans;
	for (int i = 0; i < k; ++i) {
		int ok = 1;
		for (int o = 0; o < 4; ++o) {
			int ni = x + dx[o], nj = y + dy[o];
			if (ss(ni, nj) && A[ni][nj] != '*' && D[ni][nj] <= k - i - 1) {
				x = ni, y = nj;
				ans += N[o];
				ok = 0;
				break;
			}
		}
		if (ok) return 0 * puts("IMPOSSIBLE");
	}
	cout << ans;
	return 0;
}