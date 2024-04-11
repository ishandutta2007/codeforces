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

const int N = 100000;
vector<int> l[N], r[N];
int ans[N];
int lc[N], rc[N];
int par[N];
int find(int i) {
	return (par[i] < 0) ? i : (par[i] = find(par[i]));
}
int merge(int i, int j) {
	i = find(i); j = find(j);
	if (i == j)return 0;
	if (par[i] < par[j])swap(i, j);
	par[j] += par[i];
	par[i] = j;
	return 1;
}

void solve(int s, int e, vector<pair<pii, int> >& Q) {
	if (s > e)return;
	if (Q.empty())return;
	int mid = (s + e) / 2;
	vector<pair<pii, int> > L, M, R;
	for (auto &x : Q) {
		if (x.first.second < mid) L.push_back(x);
		else if (x.first.first > mid) R.push_back(x);
		else M.push_back(x);
	}
	for (auto &x : M) {
		if (x.first.first >= mid - 4 && x.first.second <= mid + 4) {
			int a = x.first.first; int b = x.first.second;
			int d = 0;
			for (int i = a; i < b; i++) {
				for (auto &u : r[i]) if (u <= b) d += merge(i, u);
			}
			for (int i = a; i <= b; i++) par[i] = -1;
			ans[x.second] = b - a + 1 - d;
		}
	}
	int Ld = 0, Rd = 0, cur;
	for (int i = mid; i >= mid - 4 && i >= s; i--) {
		for (auto &u : r[i]) if (u <= mid) Ld += merge(u, i);
	}
	cur = 0;
	for (int i = mid - 5; i >= s; i--) {
		for (auto &u : r[i]) cur += merge(u, i);
		lc[i] = cur;
	}
	lc[mid] = 0;
	cur = 0;
	for (int i = mid + 1; i <= e; i++) {
		for (auto &u : l[i]) if(u >= s) cur += merge(u, i);
		lc[i] = cur;
	}
	for (int i = s; i <= e; i++) par[i] = -1;

	for (int i = mid; i <= mid + 4 && i <= e; i++) {
		for (auto &u : l[i])if (u >= mid)Rd += merge(u, i);
	}
	cur = 0;
	for (int i = mid + 5; i <= e; i++) {
		for (auto &u : l[i]) cur += merge(u, i);
		rc[i] = cur;
	}
	rc[mid] = 0;
	cur = 0;
	for (int i = mid - 1; i >= s; i--) {
		for (auto &u : r[i]) if(u <= e)cur += merge(u, i);
		rc[i] = cur;
	}
	for (int i = s; i <= e; i++)par[i] = -1;
	for (auto &x : M) {
		if (ans[x.second] > 0) continue;
		else if (x.first.first <= mid - 5) {
			ans[x.second] = x.first.second - x.first.first + 1 - Ld - lc[x.first.first] - lc[x.first.second];
		}
		else {
			ans[x.second] = x.first.second - x.first.first + 1 - Rd - rc[x.first.first] - rc[x.first.second];
		}
	}
	M = vector<pair<pii, int> >();
	solve(s, mid - 1, L);
	solve(mid + 1, e, R);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, k; nii(n, k);
	int m; ni(m);
	F(i, m) {
		int u, v; nii(u, v);
		u--; v--;
		if (u > v)swap(u, v);
		r[u].push_back(v);
		l[v].push_back(u);
	}
	int q; ni(q);
	vector<pair<pii,int> > Q;
	F(i, q) {
		int x, y; nii(x, y); x--; y--;
		Q.emplace_back(mp(x, y), i);
	}
	F(i, n)par[i] = -1;
	solve(0, n - 1, Q);
	F(i, q)printf("%d\n", ans[i]);
	return 0;
}