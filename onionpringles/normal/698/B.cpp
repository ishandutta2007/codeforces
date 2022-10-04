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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const int N = 200000;
int A[N];
int par[N];
int cnt[N];
int find(int i) {
	if (par[i] != i) par[i] = find(par[i]);
	return par[i];
}
int merge(int i, int j) {
	i = find(i); j = find(j);
	if (i == j) return 0;
	if (cnt[i] > cnt[j]) swap(i, j);
	cnt[j] += cnt[i];
	par[i] = j;
	return 1;
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	F(i, n) {
		ni(A[i]); A[i]--;
	}
	F(i, n) {
		cnt[i] = 1;
		par[i] = i;
	}
	vector<int> bad; int cur = -1;
	F(i, n) {
		if (i == A[i]) cur = i;
		if (!merge(i, A[i])) {
			bad.push_back(i);
		}
	}
	int sz = bad.size();
	if (cur != -1) {
		int ii = find(bad.begin(), bad.end(), cur) - bad.begin();
		swap(bad[ii], bad[sz - 1]);
	}
	for (int i = 0; i < sz - 1; i++) {
		A[bad[i]] = bad[i + 1];
	}
	A[bad[sz - 1]] = bad[sz - 1];
	if (cur != -1) sz--;
	printf("%d\n", sz);
	F(i, n) printf("%d ", A[i] + 1);
	return 0;
}