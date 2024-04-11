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
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TASK "cinema"

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

const int dd = (int)1e5 + 7;
const int INF = (int)1e9 + 7;

vector<int> A[dd];
int K[dd], m;
pair<int, int> C[dd];

bool check(int r) {
	for (int i = 0; i < m; ++i) {
		if (!A[i].size() || A[i][0] > r || !(int)A[i].size()) return false;
	}
	for (int i = 0; i < m; ++i) {
		C[i] = { A[i][upper_bound(all(A[i]), r) - A[i].begin() - 1], i };
	}
	sort(C, C + m);
	ll pd = 0;
	for (int i = 0; i < m; ++i) {
		if (K[C[i].second] > C[i].first - pd) {
			return false;
		}
		pd += K[C[i].second] + 1;
	}
	return true;
}

int main() {
	file();
	int n, x;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		if (x) A[x - 1].push_back(i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &K[i]);
	}

	int l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << (r == n ? -1 : r + 1);
	return 0;
}