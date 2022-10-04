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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//


map<int, int> S;
ll ans = 0;
void add(int x, int y, int v) {
	auto it = S.upper_bound(x);
	it--;
	if (it->second >= y) return;
	it = S.lower_bound(x);
	ll area = 0;
	while (1) {
		if (it->second > y) break;
		auto it2 = it;
		it2--;
		int dy = it->second - it2->second;
		it2 = it;
		it++;
		int dx = it->first - it2->first;
		area += (ll)dx*dy;
		S.erase(it2);
	}
	auto it2 = S.lower_bound(x);
	it2--;
	int dy = y - it2->second;
	int dx = it->first - x;
	area = (ll)dx*dy - area;
	ans += area*v;
	S[x] = y;
}

const int N =201010;
int a[N];
vector<int> b[N];
vector<int> c[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	FF(i, n - 1)S[i] = i;
	S[-1] = 0;
	S[n] = n + 1;
	F(i, n) b[a[i]].push_back(i);
	FF(i, N - 1) {
		for (int j = i; j < N; j += i) {
			for (auto &x : b[j])c[i].push_back(x);
		}
		sort(c[i].begin(), c[i].end());
	}
	for (int i = N - 1; i >= 1; i--) {
		if (c[i].size() <= 1)continue;
		int sz = c[i].size();
		add(c[i][1] + 1, n, i);
		add(0, c[i][sz - 2], i);
		add(c[i][0] + 1, c[i][sz - 1], i);
	}
	printf("%I64d\n", ans);
}