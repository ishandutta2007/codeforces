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
int cnt[N], rnk[N];
ll ds[N];
vector<int> adj[N];
void dfs0(int u, int p=-1) {
	cnt[u] = 1;
	for (auto &x : adj[u]) {
		if (x == p)continue;
		rnk[x] = rnk[u] + 1;
		dfs0(x, u);
		cnt[u] += cnt[x];
		ds[u] += ds[x] + cnt[x];
	}
}
int k;
ll ans = 0;
vector<int> dfs2(int u, int p = -1) {
	vector<int> res(k);
	for (auto &x : adj[u]) {
		if (x == p)continue;
		vector<int> R = dfs2(x, u);
		F(i, k) {
			F(j, k) {
				int dif = (i + j + k - 1) / k - (i + k - 1) / k - (j + k - 1) / k;
				int ii = (rnk[u] + i) % k;
				int jj = (rnk[u] + j) % k;
				ans += (ll)dif*res[ii] * R[jj];
			}
		}
		F(i, k)res[i] += R[i];
		ll d = ds[x] + cnt[x];
		F(i, k) {
			if (i == 0)continue;
			int ii = (rnk[u] + i) % k;
			d += (k - i)*R[ii];
		}
		ans += (ll)(d / k)*(cnt[u] - cnt[x]);
	}
	res[rnk[u] % k]++;
	return res;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; nii(n, k);
	F(i, n - 1) {
		int u, v; nii(u, v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs0(0);
	dfs2(0);
	printf("%I64d\n", ans);
	return 0;
}