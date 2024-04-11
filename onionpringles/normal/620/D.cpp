#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int a[2000];
int b[2000];
int tmpa[2000];
int tmpb[2000];
pii tta[1999000];
pii ttb[1999000];
int n, m;
ll sa;
ll sb;

pii solve1(ll& ans1) {
	for (int i = 0; i < 2000; i++) {
		tmpa[i] = tmpb[i] = i;
	}
	sort(tmpa, tmpa + n, [&](const int& x, const int& y)->bool {return a[x] < a[y]; });
	sort(tmpb, tmpb + m, [&](const int& x, const int& y)->bool {return b[x] < b[y]; });

	ll dif = sb - sa; int curind = 0; ans1 = 6000000000000000000LL;
	pii ind;
	for (int i = 0; i < n; i++) {
		while (curind < m && 2*((ll)b[tmpb[curind]] - a[tmpa[i]]) < dif) curind++;
		if (curind < m) {
			ll tmp = 2 * ((ll)b[tmpb[curind]] - a[tmpa[i]]) - dif;
			if (ans1 > tmp) {
				ans1 = tmp;
				ind.first = tmpa[i];
				ind.second = tmpb[curind];
			}
		}
		if (curind > 0) {
			ll tmp = dif - 2 * ((ll)b[tmpb[curind - 1]] - a[tmpa[i]]) ;
			if (ans1 > tmp) {
				ans1 = tmp;
				ind.first = tmpa[i];
				ind.second = tmpb[curind - 1];
			}
		}
	}
	return ind;
}

pair<pii, pii> solve2(ll& ans2) {
	ans2 = 6000000000000000000LL;
	int N = n*(n - 1) / 2;
	int M = m*(m - 1) / 2;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			tta[k].first = i;
			tta[k++].second = j;
		}
	}
	k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			ttb[k].first = i;
			ttb[k++].second = j;
		}
	}

	sort(tta, tta + N, [&](const pii& x, const pii& y)->bool {return a[x.first] + a[x.second] < a[y.first] + a[y.second]; });
	sort(ttb, ttb + M, [&](const pii& x, const pii& y)->bool {return b[x.first] + b[x.second] < b[y.first] + b[y.second]; });
	ll dif = sb - sa; int curind = 0;
	pair<pii, pii> ind;
	for (int i = 0; i < N; i++) {
		while (curind < M && 2 * ((ll)b[ttb[curind].first] + b[ttb[curind].second] - a[tta[i].first] - a[tta[i].second]) <= dif) curind++;
		if (curind < M) {
			ll tmp = 2 * ((ll)b[ttb[curind].first] + b[ttb[curind].second] - a[tta[i].first] - a[tta[i].second]) -dif;
			if (ans2 > tmp) {
				ans2 = tmp;
				ind.first = tta[i];
				ind.second = ttb[curind];
			}
		}
		if (curind > 0) {
			ll tmp = dif - 2 * ((ll)b[ttb[curind - 1].first] + b[ttb[curind-1].second] - a[tta[i].first] - a[tta[i].second]);
			if (ans2 > tmp) {
				ans2 = tmp;
				ind.first = tta[i];
				ind.second = ttb[curind - 1];
			}
		}
	}
	return ind;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ni(n); 
	for (int i = 0; i < n; i++) {
		ni(a[i]);
		sa += a[i];
	}
	
	ni(m); 
	for (int i = 0; i < m; i++) {
		ni(b[i]);
		sb += b[i];
	}
	int swapflag = 0;
	if (sa > sb) {
		swap(a, b);
		swap(sa, sb);
		swap(n, m);
		swapflag = 1;
	}

	//sa<=sb

	ll ans0 = sb - sa;
	ll ans1;
	pii x = solve1(ans1);
	ll ans2;
	auto y = solve2(ans2);
	ll _m = min(ans0, min(ans1, ans2));
	if (swapflag) {
		swap(x.first, x.second);
		swap(y.first, y.second);
	}
	printf("%I64d\n", _m);
	if (_m == ans0) {
		puts("0");
	}
	else if (_m == ans1) {
		puts("1");
		printf("%d %d", x.first + 1, x.second + 1);
	}
	else {
		puts("2");
		printf("%d %d\n%d %d", y.first.first + 1,1 + y.second.first, 1 + y.first.second, 1 + y.second.second);
	}
	return 0;
}