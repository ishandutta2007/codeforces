#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef double ld;

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	solve();
	return  0;
}

const int dd = (int)6e4 + 7;
const int inf = (int)1e9 + 7;

struct st {
	int x, v;
} A[dd];
int n;

ld get(ld X) {
	ld ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, abs(A[i].x - X) / A[i].v);
	return ans;
}

int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i].x);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i].v);

	ld l = 1, r = 1e9;
	for (int it = 0; it < 200; ++it) {
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;
		if (get(m1) > get(m2))
			l = m1;
		else
			r = m2;
	}
	printf("%.10f", get(l));
	return 0;
}