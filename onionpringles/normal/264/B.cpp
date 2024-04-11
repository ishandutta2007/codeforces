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

const int N = 100010;
int a[N];
vector<int> g[N];
int dp[N];

vector<int> fac(int n) {
	vector<int> ret;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			ret.push_back(i);
			while (n%i == 0)n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

int main() {
#ifndef __GNUG__
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	F(i, n) {
		vector<int> P = fac(a[i]);
		int M = 1;
		for (auto p : P) {
			if (g[p].empty())continue;
			int x = g[p].back();
			M = max(M, dp[x] + 1);
		}
		for (auto p : P) g[p].push_back(i);
		dp[i] = M;
	}
	printf("%d\n", *max_element(dp, dp + n));
	return 0;
}