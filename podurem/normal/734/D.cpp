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

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

pair<int, int> R[dd], B[dd];
int iB, iR;

map<int, vector<pair<int, char> > > MaG, MaX, MaY, MaP;

int solve() {
	int n;
	scanf("%d", &n);
	int x0, y0;
	scanf("%d%d", &x0, &y0);

	MaX[x0].push_back({ y0, 'K' });
	MaY[y0].push_back({ x0, 'K' });
	MaP[x0 + y0].push_back({ x0, 'K' });
	MaG[x0 - y0].push_back({ x0, 'K' });

	char c;
	int x, y;
	for (int i = 0; i < n; ++i) {
		scanf("\n%c %d %d", &c, &x, &y);
		MaX[x].push_back({ y, c });
		MaY[y].push_back({ x, c });
		MaP[x + y].push_back({ x, c });
		MaG[x - y].push_back({ x, c });
	}

	sort(MaX[x0].begin(), MaX[x0].end());
	sort(MaY[y0].begin(), MaY[y0].end());
	sort(MaP[x0 + y0].begin(), MaP[x0 + y0].end());
	sort(MaG[x0 - y0].begin(), MaG[x0 - y0].end());

	auto it = lower_bound(MaX[x0].begin(), MaX[x0].end(), make_pair(y0, 'K'));

	it++;
	if (it != MaX[x0].end()) {
		if (it->second == 'Q' || it->second == 'R') return 0 * puts("YES");
	}
	it--;
	if (it != MaX[x0].begin()) {
		it--;
		if (it->second == 'Q' || it->second == 'R') return 0 * puts("YES");
	}


	it = lower_bound(MaY[y0].begin(), MaY[y0].end(), make_pair(x0, 'K'));

	it++;
	if (it != MaY[y0].end()) {
		if (it->second == 'Q' || it->second == 'R') return 0 * puts("YES");
	}
	it--;
	if (it != MaY[y0].begin()) {
		it--;
		if (it->second == 'Q' || it->second == 'R') return 0 * puts("YES");
	}


	it = lower_bound(MaP[x0 + y0].begin(), MaP[x0 + y0].end(), make_pair(x0, 'K'));

	it++;
	if (it != MaP[x0 + y0].end()) {
		if (it->second == 'Q' || it->second == 'B') return 0 * puts("YES");
	}
	it--;
	if (it != MaP[x0 + y0].begin()) {
		it--;
		if (it->second == 'Q' || it->second == 'B') return 0 * puts("YES");
	}


	it = lower_bound(MaG[x0 - y0].begin(), MaG[x0 - y0].end(), make_pair(x0, 'K'));

	it++;
	if (it != MaG[x0 - y0].end()) {
		if (it->second == 'Q' || it->second == 'B') return 0 * puts("YES");
	}
	it--;
	if (it != MaG[x0 - y0].begin()) {
		it--;
		if (it->second == 'Q' || it->second == 'B') return 0 * puts("YES");
	}

	puts("NO");


	return 0;
}