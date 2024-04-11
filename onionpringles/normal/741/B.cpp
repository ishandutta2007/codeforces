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
int par[N]; vector<int> cc[N];
int find(int i) {
	if (par[i] < 0)return i;
	else return par[i] = find(par[i]);
}
void merge(int i, int j) {
	i = find(i); j = find(j);
	if (i == j)return;
	if (par[i] < par[j])swap(i, j);
	par[j] += par[i]; par[i] = j;
}
int a[N], b[N];
int d[1001][1001];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, w; nii(n, m); ni(w);
	F(i, n)ni(a[i]);
	F(i, n)ni(b[i]);
	F(i, n)par[i] = -1;
	F(i, m) {
		int x, y; nii(x, y); x--; y--;
		merge(x, y);
	}
	F(i, n) cc[find(i)].push_back(i);
	FF(i, n) {
		int ii = i - 1;
		FF(j, w) {
			d[i][j] = d[i - 1][j]; continue;
		}
		vector<pii> V;
		int sa = 0, sb = 0;
		for (auto &x : cc[ii]) {
			V.emplace_back(a[x], b[x]);
			sa += a[x]; sb += b[x];
		}
		V.emplace_back(sa, sb);
		FF(j, w) {
			d[i][j] = d[i-1][j];
			for (auto &p : V) {
				if (p.first > j)continue;
				d[i][j] = max(d[i][j], d[i-1][j - p.first] + p.second);
			}
		}
	}
	printf("%d\n", d[n][w]);
	return 0;
}