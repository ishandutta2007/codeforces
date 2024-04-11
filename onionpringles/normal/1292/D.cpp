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
	while (n)n -= n & (-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 5001;
int chk[N], e[N][N], S[N][N], a[N];
vector<int> P;

ll Do(int l, int r, int i, ll A, ll B) {
	if (i == -1)return B;
	int curl = l, curr;
	int p = P[i];
	ll SL = 0, SR = 0, S = 0, cL = 0, cR = 0;
	if (i) {
		for (int k = l; k < r; k++)S += 1LL*::S[i - 1][k]*a[k];
	}
	for (int k = l; k < r; k++)SR += 1LL*a[k] * e[i][k], cR += a[k];
	ll Ans = infl;
	while (curl < r) {
		curr = curl / p * p + p;
		if (curr > r)curr = r;
		ll SS = S;
		int cur = 0;
		if (i) {
			for (int k = curl; k < curr; k++)SS -= 1LL*::S[i - 1][k] * a[k];
		}
		for (int k = curl; k < curr; k++) {
			SR -= 1LL*e[i][k] * a[k];
			cR -= a[k];
			cur += a[k];
		}
		int E = e[i][curl];
		ll Dif = 1LL * E*cL - SL + SR - E*cR;
		Ans = min(Ans, Do(curl, curr, i - 1, A + cL + cR, B + Dif + SS + A * E));
		for (int k = curl; k < curr; k++) {
			SL += 1LL*e[i][k] * a[k];
			cL += a[k];
		}
		curl = curr;
	}
	return Ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 2; i < N; i++) {
		if (chk[i])continue;
		P.push_back(i);
		for (int j = i + i; j < N; j += i)chk[j] = 1;
	}
	int m = P.size();
	for (int i = 0; i < m; i++){
		int p = P[i];
		for (int j = 1; j < N; j++) {
			e[i][j] = e[i][j / p] + j / p;
			if (i)S[i][j] = S[i - 1][j] + e[i][j];
			else S[i][j] = e[i][j];
		}
	}
	int n; ni(n);
	F(i, n) {
		int x; ni(x);
		a[x]++;
	}
	printf("%lld\n",Do(0, N, m - 1, 0, 0));
	return 0;
}