#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <numeric>
#include <queue>

using namespace std;

typedef long long ll;
typedef double ld;

int solve();
#define TASK "robots"
#define err(...) fprintf(stdout, __VA_ARGS__), fflush(stdout)

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}


const int dd = (int)2e4 + 1;

int cnt[dd], G[dd];

int solve() {
	for (int i = 0; i < dd; i++) {
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		G[t]++;
	}

	ll ans = 0;
	for (int i = 0; i <= 10000; i++) {
		if (G[i] == 0) continue;
		for (int j = i + 1; j <= 10000; j++) {
			if (cnt[i ^ j] == k)
				ans += 1ll * G[j] * G[i];
		}
		if (k == 0)
			ans += 1ll * G[i] * (G[i] - 1) / 2;
	}
	printf("%I64d\n", ans);
	return 0;
}