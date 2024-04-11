#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string.h>
#include <string>

#define mp make_pair
#define mtp make_tuple
#define ni(x) scanf("%d", &(x))
#define nii(x, y) scanf("%d%d", &(x), &(y))

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

char buf[400000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%s", buf);
	int n = strlen(buf);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (buf[i] == '4' || buf[i] == '8' || buf[i] == '0') {
			ans++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int tt = 10 * (buf[i] - '0') + (buf[i + 1] - '0');
		if (tt % 4 == 0) {
			ans += (i + 1);
		}
	}
	printf("%I64d", ans);

	return 0;
}