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

const int N = 500010;
const int B = 1 << 19;
vector<pii> tr[B << 1];
int a[N], chk[N], res[N], clk, b[N];

int n;
void dfs(int u) {
	chk[u] = 1;
	if (a[u] != inf) if (!chk[a[u]])dfs(a[u]);

	int x = b[u];
	if (b[u] == -1) x = n + 1;
	int L = 0;
	for (L += B, x += B; L / 2 != x / 2; L /= 2, x /= 2) {
		if (!(L & 1)) {
			while (!tr[L + 1].empty() && tr[L + 1].back().first > u) {
				int v = tr[L + 1].back().second;
				tr[L + 1].pop_back();
				if (!chk[v])dfs(v);
			}
		}
		if (x & 1) {
			while (!tr[x - 1].empty() && tr[x - 1].back().first > u) {
				int v = tr[x - 1].back().second;
				tr[x - 1].pop_back();
				if (!chk[v])dfs(v);
			}
		}
	}
	res[u] = clk++;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ni(n);
	FF(i, n)ni(a[i]);
	FF(i, n)b[i] = -1;
	FF(i, n) {
		if (a[i] == -1) a[i] = inf;
		else b[a[i]] = i;
		tr[B + i].push_back(pii(a[i], i));
	}
	for (int i = B - 1; i; i--)merge(tr[i << 1].begin(), tr[i << 1].end(), tr[i << 1 | 1].begin(), tr[i << 1 | 1].end(), back_inserter(tr[i]));
	FF(i, n)if (!chk[i])dfs(i);
	FF(i, n)printf("%d ", n - res[i]); puts("");
	return 0;
}