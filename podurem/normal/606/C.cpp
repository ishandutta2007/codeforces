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
	int n;
	scanf("%d", &n);
	vector<int> a(n), B(n + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		B[a[i]] = i;
	}
	vector<bool> U(n + 1, 0);
	int ans = n;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if (!U[x]) {
			U[x] = 1;
			while (x != n && B[x + 1] > B[x]) {
				++x;
				U[x] = 1;
			}
			ans = min(ans, n - (x - a[i] + 1));
		}
	}
	printf("%d", ans);
	return 0;
}