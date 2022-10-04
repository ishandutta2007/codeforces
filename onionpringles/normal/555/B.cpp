#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define ni(n) scanf("%d", &(n))
#define mp make_pair
#ifndef __GNUG__
#define __INT_MAX__ 2147483647
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pair<pair<ll, ll>, int> isl[200000];
multimap<ll, int> br;
int ans[200000];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	ll svl, svr;
	for (int i = 0; i < n; i++) {
		ll l, r;
		scanf("%I64d%I64d", &l, &r);
		if (i == 0) {
			svl = l; svr = r; continue;
		}
		isl[i - 1] = mp(mp(r - svl, -(l - svr)), i - 1);
		svl = l;
		svr = r;
	}
	for (int i = 0; i < m; i++) {
		ll k; scanf("%I64d", &k);
		br.insert(mp(k,i));
	}
	sort(isl, isl + (n - 1));
	for (int i = 0; i < n - 1; i++) {
		auto it = br.lower_bound(-isl[i].first.second);
		if (it == br.end()) {
			puts("No"); return 0;
		}
		if (it->first <= isl[i].first.first) {
			ans[isl[i].second] = it->second;
			br.erase(it);
		}
		else {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", ans[i] + 1);
	}
	return 0;
}