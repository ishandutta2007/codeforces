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

	int n, k; nii(n, k);
	scanf("%s", buf);
	char begin = 'a';
	char end = 'z';
	for (int i = 0; i < n; i++) {
		if (buf[i] - begin > end - buf[i]) {
			if (k <= buf[i] - begin) {
				buf[i] -= k; k = 0;
				break;
			}
			else {
				k -= (buf[i] - begin);
				buf[i] = begin;
			}
		}
		else {
			if (k <= end - buf[i]) {
				buf[i] += k; k = 0;
				break;
			}
			else {
				k -= (end - buf[i]);
				buf[i] = end;
			}
		}
	}
	
	if (k > 0) {
		puts("-1");
	}
	else printf("%s", buf);
	return 0;
}