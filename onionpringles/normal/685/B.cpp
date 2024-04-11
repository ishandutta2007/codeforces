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
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 300000;

vector<int> adj[N];
int ans[N];
int sz[N];
int anc[N][19];
int rnk[N];
void dfs(int i) {
	sz[i] = 1;
	for (auto &x : adj[i]) {
		rnk[x] = rnk[i] + 1;
		dfs(x);
		sz[i] += sz[x];
	}
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	nii(n, q);
	F(i, n - 1) {
		int p; ni(p); p--;
		anc[i + 1][0] = p;
		adj[p].push_back(i + 1);
	}
	rnk[0] = 0;
	dfs(0);
	anc[0][0] =  -1;
	FF(j, 18) {
		F(i, n) {
			int a = anc[i][j - 1];
			if (a == -1) anc[i][j] = -1;
			else anc[i][j] = anc[a][j - 1];
		}
	}
	F(i, n) {
		int M = 0;
		for (auto &x : adj[i]) M = max(M, sz[x]);
		if (2 * M <= sz[i]) {
			ans[i] = i;
		}
		int cur = i;
		for (int j = 18; j >= 0; j--) {
			int a = anc[cur][j];
			if (a == -1) continue;
			if (sz[a] < 2 * M) {
				cur = a;
			}
		}
		cur = anc[cur][0];

		M = sz[i];
		for (; cur != -1 && sz[cur] <= 2*M; cur = anc[cur][0]) {
			ans[cur] = i;
		}
	}
	F(i, q) {
		int qq; ni(qq);
		printf("%d\n", ans[qq - 1] + 1);
	}

	return 0;
}