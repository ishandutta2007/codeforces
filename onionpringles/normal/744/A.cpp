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
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const int N = 1000;
int par[N];
int find(int i) {
	if (par[i] >= 0)return par[i] = find(par[i]);
	else return i;
}
void merge(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)return;
	if (par[i] < par[j])swap(i, j);
	par[j] += par[i];
	par[i] = j;
}
int chk[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m); int k; ni(k);
	vector<int> K;
	F(i, n)par[i] = -1;
	F(i, k) {
		int x; ni(x); x--;
		K.push_back(x);
	}
	F(i, m) {
		int a, b; nii(a, b);
		a--; b--;
		merge(a, b);
	}
	vector<int> A, B;
	F(i, k) {
		int x = K[i];
		int t = find(x);
		chk[t] = 1;
		A.push_back(-par[t]);
	}
	F(i, n) {
		int j = find(i);
		if (chk[j])continue;
		chk[j] = 1;
		B.push_back(-par[j]);
	}
	int x = *max_element(A.begin(), A.end());
	int xx = x;
	for (auto &y : B) x += y;
	int ed = 0;
	for (auto &a : A) {
		ed += a*(a - 1) / 2;
	}
	ed -= xx*(xx - 1) / 2;
	ed += x*(x - 1) / 2;
	printf("%d\n", ed - m);
	return 0;
}