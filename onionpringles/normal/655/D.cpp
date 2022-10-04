#pragma warning(disable:4996)

#include <stdio.h>
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
#include <random>
#include <time.h>
#include <tuple>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define F_(i,n) for(int i = 1; i <= (n); i++)
#define println(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

vector<int> adj[100000];

pii ed[100000];
int vis[100000];

int stk[100000];
int sp = 0;

void dfs(int i) {
	vis[i] = 1;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		dfs(x);
	}
	stk[sp++] = i;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	F(i, m) {
		int u, v;
		nii(u, v);
		u--; v--;
		ed[i] = mp(u, v);
	}
	int low = 1; int high = m + 1;
	while (low != high) {
		int mid = (low + high) / 2;
		F(i, mid) {
			adj[ed[i].first].push_back(ed[i].second);
		}
		F(i, n) {
			if (vis[i]) continue;
			dfs(i);
		}
		int bad = 0;
		F_(i, n - 1) {
			int u = stk[i];
			int v = stk[i - 1];
			int good = 0;
			for (auto &x : adj[u]) {
				if (x == v) {
					good = 1;
					break;
				}
			}
			if (!good) {
				bad = 1;
				break;
			}
		}
		memset(vis, 0, sizeof(vis));
		F(i, n)adj[i].clear();
		sp = 0;
		if (bad)low = mid + 1;
		else high = mid;
	}

	if(high <= m) println(high);
	else puts("-1");

	return 0;
}