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

const int N = 200000;

vector<int> adj[N];
int par[N];
int d[N], e[N], f[N];

int inv(int m) {
	if (m == 1)return 1;
	else return mul(mod - mod / m, inv(mod%m));
}

vector<int> solve(vector<int> V) {
	int n = V.size();
	if (n == 0) return vector<int>();
	if (n == 1)return{ 1 };
	int h = n / 2;
	vector<int> V2;
	for (int i = h; i < n; i++) V2.push_back(V[i]);
	V.resize(h);
	vector<int> a, b;
	a = solve(V);
	b = solve(V2);
	int x = 1, y = 1;
	F(i, h)x = mul(x, 1 + d[V[i]]);
	for (int i = h; i < n; i++) y = mul(y, 1 + d[V2[i - h]]);
	F(i, h) a[i] = mul(a[i], y);
	for (int i = h; i < n; i++)a.push_back(mul(x, b[i - h]));
	return a;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n - 1) {
		int x; ni(x);
		x--;
		adj[x].push_back(i + 1);
		par[i + 1] = x;
	}
	for (int i = n - 1; i >= 0; i--) {
		d[i] = 1;
		for (auto &x : adj[i]) {
			d[i] = mul(d[i], 1 + d[x]);
		}
		vector<int> V = solve(adj[i]);
		int sz = adj[i].size();
		F(j, sz)f[adj[i][j]] = V[j];
	}
	e[0] = 1;
	FF(i, n - 1) {
		e[i] = mul(e[par[i]], f[i]);
		e[i] = (e[i] + 1) % mod;
	}
	F(i, n) {
		printf("%d ", (int)mul(e[i], d[i]));
	}
	puts("");
	return 0;
}