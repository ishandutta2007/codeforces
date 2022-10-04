#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <array>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n&(-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000003;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 301010;

int s[N], t[N], a[N];
vector<pair<pii, int>> ans;
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(s[i]);
	F(i, n)ni(t[i]);
	F(i, n)a[i] = i;
	sort(a, a + n, [](int i, int j) {return s[i] > s[j]; });
	sort(t, t + n, greater<int>());
	ll sum = 0;
	F(i, n) {
		sum += s[a[i]];
		sum -= t[i];
		if (sum < 0)return puts("NO"), 0;
	}
	if (sum)return puts("NO"), 0;
	int j = 0;
	F(i, n) {
		if (i == j)j++;
		while (s[a[i]] != t[i]) {
			while (s[a[j]] >= t[j])j++;
			int d = min(s[a[i]] - t[i], t[j] - s[a[j]]);
			ans.push_back({ {a[j],a[i]},d });
			s[a[i]] -= d;
			s[a[j]] += d;
		}
	}
	puts("YES");
	printf("%d\n", (int)ans.size());
	for (auto &x : ans)printf("%d %d %d\n", x.first.first + 1, x.first.second + 1, x.second);
}