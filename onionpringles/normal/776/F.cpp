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
vector<int> adj[N];
vector<int> adj2[N];
vector<int> L[N];
int n, m;
int num = 0;

int dfs(int i, int pos, int pn = -1) {
	int cur = num++;
	if (pn != -1) adj2[cur].push_back(pn);
	int st = i;
	while (1) {
		L[cur].push_back(i);
		if (pos) {
			int v = dfs(i, pos - 1, cur);
			adj2[cur].push_back(v);
		}
		int pst = i;
		i = adj[i][pos];
		pos = lower_bound(adj[i].begin(),adj[i].end(), pst, [&](int x, int y) {
			return (x - i + n) % n < (y - i + n) % n;
		}) - adj[i].begin() - 1;
		if (pn == -1) {
			if (i == st) break;
		}
		else {
			if (adj[i][pos] == st) {
				L[cur].push_back(i);
				break;
			}
		}
	}
	return cur;
}

int ans[N];
int chk[N];
int cnt[N];
int mcnt[N];
void dfs2(int u, vector<int>& V) {
	V.push_back(u);
	chk[u] = 1;
	cnt[u] = 1;
	mcnt[u] = 0;
	for (auto &x : adj2[u]) {
		if (chk[x]) continue;
		dfs2(x, V);
		cnt[u] += cnt[x];
		mcnt[u] = max(mcnt[u], cnt[x]);
	}
}
void cent(int u, int clr = 0) {
	vector<int> V;
	dfs2(u, V);
	int m = V.size();
	int c = -1;
	for (auto &x : V) {
		if (max(mcnt[x], m - cnt[x]) <= m / 2) {
			c = x;
			break;
		}
	}
	assert(c != -1);
	ans[c] = clr;
	for (auto &x : V)chk[x] = 0;
	chk[c] = 2;
	for (auto &x : adj2[c]) {
		if (chk[x] != 2) cent(x, clr + 1);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	nii(n, m);
	F(i, n) {
		adj[i].push_back((i + 1) % n);
		adj[i].push_back((i + n - 1) % n);
	}
	F(i, m) {
		int x, y; nii(x, y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	F(i, n) {
		sort(adj[i].begin(), adj[i].end(), [&](int x, int y) {
			return (x - i + n) % n < (y - i + n) % n;
		});
	}
	dfs(0, 0, -1);
	F(i, num)sort(L[i].begin(), L[i].end(), greater<int>());
	vector<int> V(num);
	vector<int> Vi(num);
	F(i, num)V[i] = i;
	sort(V.begin(), V.end(), [](int i, int j) {return L[i] < L[j]; });
	F(i, num)Vi[V[i]] = i;
	cent(0);
	F(i, num) printf("%d ", ans[V[i]] + 1);
	return 0;
}