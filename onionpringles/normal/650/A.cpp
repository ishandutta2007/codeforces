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

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		nii(a, b);
		xx.push_back(mp(a, b));
	}
	sort(xx.begin(), xx.end());
	ll ans = 0;
	ll badans = 0;
	int cnt = 1; int bcnt = 1;
	for (int i = 1; i < n; i++) {
		if (xx[i].first == xx[i-1].first) {
			cnt++;
		}
		else {
			ans += (ll)cnt*(cnt - 1) / 2;
			cnt = 1;
		}
		if (xx[i] == xx[i - 1]) {
			bcnt++;
		}
		else {
			badans += (ll)bcnt*(bcnt - 1) / 2;
			bcnt = 1;
		}
	}
	ans += (ll)cnt*(cnt - 1) / 2;
	badans += (ll)bcnt*(bcnt - 1) / 2;
	sort(xx.begin(), xx.end(), [](const pii& x, const pii& y) {return x.second < y.second; });
	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (xx[i].second == xx[i - 1].second) {
			cnt++;
		}
		else {
			ans += (ll)cnt*(cnt - 1) / 2;
			cnt = 1;
		}
	}
	ans += (ll)cnt*(cnt - 1) / 2;
	printf("%I64d", ans - badans);

	return 0;
}