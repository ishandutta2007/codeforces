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
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	vector<pii> A, B;
	int n; ni(n);
	int c, d; nii(c, d);
	F(i, n) {
		int a, b; char c;
		scanf("%d %d %c", &a, &b, &c);
		if (c == 'C') {
			A.emplace_back(b, a);
		}
		else B.emplace_back(b, a);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int x = A.size();
	int y = B.size();
	vector<int> C(x), D(y);
	int ans = 0;
	F(i, x) {
		int p = A[i].first;
		int j = lower_bound(A.begin(), A.end(), pii(c - p, inf)) - A.begin();
		if (j > i)j = i;
		if (j)ans = max(ans, A[i].second + C[j - 1]);
		if(i)C[i] = max(C[i - 1], A[i].second);
		else C[i] = A[i].second;
	}
	F(i, y) {
		int p = B[i].first;
		if (p > d)break;
		int j = lower_bound(B.begin(), B.end(), pii(d - p, inf)) - B.begin();
		if (j > i)j = i;
		if (j)ans = max(ans, B[i].second + D[j - 1]);
		if (i)D[i] = max(D[i - 1], B[i].second);
		else D[i] = B[i].second;
	}
	int j1 = lower_bound(A.begin(), A.end(), pii(c, inf)) - A.begin();
	int j2 = lower_bound(B.begin(), B.end(), pii(d, inf)) - B.begin();
	if (j1 && j2) ans = max(ans, C[j1 - 1] + D[j2 - 1]);
	printf("%d\n", ans);
	return 0;
}