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

const int N = 301000;
vector<int> adj[N];
int q[N];
int par[N];
int chk[N];
int dist[N];
int qs, qe;
int cnt[N];
int dg[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	F(i, m) {
		int u, v;
		nii(u, v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		dg[u]++; dg[v]++;
	}
	int x = 0;
	F(i, n) {
		if (dg[i] != n - 1)x = i;
	}
	dist[x] = 0;
	chk[x] = 1;
	q[qe++] = x;
	while (qs < qe) {
		int u = q[qs++];
		for (auto &x : adj[u]) {
			if (!chk[x]) {
				dist[x] = dist[u] + 1;
				chk[x] = 1;
				q[qe++] = x;
			}
		}
	}
	int s = max_element(dist, dist + n) - dist;
	qs = qe = 0;
	dist[s] = 0;
	F(i, n)chk[i] = 0;
	chk[s] = 1;
	q[qe++] = s;
	while (qs < qe) {
		int u = q[qs++];
		for (auto &x : adj[u]) {
			if (!chk[x]) {
				dist[x] = dist[u] + 1;
				chk[x] = 1;
				q[qe++] = x;
			}
		}
	}
	vector<int> V;
	for (auto &x : adj[s]) {
		int cc = 0;
		for (auto &y : adj[x]) {
			if (dist[y] == 2)cc++;
		}
		if (cc == 0) {
			dist[x] = 0;
		}
	}
	F(i, n)cnt[dist[i]]++;
	bool bad = false;
	F(i, n) {
		int cm = 0, c0 = 0, c1 = 0;
		for (auto &x : adj[i]) {
			if (dist[x] == dist[i] + 1)c1++;
			else if (dist[x] == dist[i]) c0++;
			else cm++;
		}
		if (c1 != cnt[dist[i] + 1])bad = true;
		if (c0 != cnt[dist[i]] - 1)bad = true;
		if (dist[i] && cm != cnt[dist[i] - 1])bad = true;
	}
	if (bad)return puts("NO"), 0;
	puts("YES");
	F(i, n) {
		printf("%d ", dist[i] + 1);
	}
	return 0;
}