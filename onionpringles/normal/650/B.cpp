#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <complex>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> xx;

char buf[500001];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n); int a, b, T; nii(a, b); ni(T); scanf("%s", buf);
	int low = 1; int high = n + 1;
	while (low != high) {
		int mid = (low + high) >> 1;
		ll _m = 1000000001; int hh = 0;
		for (int i = 0; i < mid; i++) {
			if (buf[i] == 'w') hh += b;
		}
		for (int i = mid - 1; i >= 0; i--) {
			ll cur = (i + mid - 1)*a + hh;
			if (i == mid - 1) cur = (mid - 1)*a + hh;
			_m = min(_m, cur + mid);
			if (buf[i] == 'w') hh -= b;
			if (buf[n - mid + i] == 'w') hh += b;
		}
		if (_m > T) high = mid;
		else low = mid + 1;
	}
	int sv = low - 1;

	for (int i = 1; i < n - i; i++) {
		swap(buf[i], buf[n - i]);
	}

	low = 0; high = n;
	while (low != high) {
		int mid = (low + high) >> 1;
		ll _m = 1000000001; int hh = 0;
		for (int i = 0; i < mid; i++) {
			if (buf[i] == 'w') hh += b;
		}
		for (int i = mid - 1; i >= 0; i--) {
			ll cur = (i + mid - 1)*a + hh;
			if (i == mid - 1) cur = (mid - 1)*a + hh;
			_m = min(_m, cur + mid);
			if (buf[i] == 'w') hh -= b;
			if (buf[n - mid + i] == 'w') hh += b;
		}
		if (_m > T) high = mid;
		else low = mid + 1;
	}
	sv = max(sv, low - 1);
	printf("%d", sv);
	return 0;
}