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
int c[N];
int chk[N];
void dfs(int u, int cl) {
	chk[u] = 1;
	for (auto &x : adj[u]) {
		if (chk[x])continue;
		if (c[x] != cl) throw 1;
		dfs(x, cl);
	}
}

bool check(int u, int n) {
	memset(chk, 0, sizeof(chk));
	chk[u] = 1;
	try {
		for (auto &x : adj[u]) {
			dfs(x, c[x]);
		}
	}
	catch (int x) {
		return false;
	}
	return true;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n - 1) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	F(i, n)ni(c[i]);
	F(i, n)for (auto &x : adj[i]) {
		if (c[i] != c[x]) {
			if (check(i, n)) {
				puts("YES");
				printf("%d\n", i + 1);
				return 0;
			}
			else if (check(x, n)) {
				puts("YES");
				printf("%d\n", x + 1);
				return 0;
			}
			else {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES\n1");

	return 0;
}