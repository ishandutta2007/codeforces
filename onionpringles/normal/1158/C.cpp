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
#include <array>
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

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n&(-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 501010;
const int B = 1 << 19;

vector<int> V;
int a[N], chk[N], n, b[N], c[N], stk[N], sp;
vector<int> tr[B << 1];
void dfs(int u) {
	chk[u] = 1;
	if (a[u] != -1 && a[u] != n + 1) {
		if (!chk[a[u]])dfs(a[u]);
	}
	for (int i = u + B; i; i /= 2) {
		while (!tr[i].empty()) {
			int v = tr[i].back();
			tr[i].pop_back();
			if (!chk[v])dfs(v);
		}
	}
	V.push_back(u);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int T; ni(T);
	while (T--) {
		 ni(n);
		FF(i, n) {
			ni(a[i]);
			if (a[i] == -1)continue;
			if (a[i] != i + 1) {
				for (int l = i + B, r = a[i] + B; l / 2 != r / 2; l /= 2, r /= 2) {
					if (!(l & 1))tr[l + 1].push_back(i);
					if (r & 1)tr[r - 1].push_back(i);
				}
			}
		}
		FF(i, n)if (!chk[i])dfs(i);
		F(i, n)c[V[i]] = n - i;
		sp = 0;
		for (int i = n; i;i--) {
			while (sp&&c[stk[sp - 1]] < c[i])sp--;
			b[i] = sp ? stk[sp - 1] : n + 1;
			stk[sp++] = i;
		}
		bool bad = false;
		FF(i, n) {
			if (a[i] != -1 && a[i] != b[i])bad = true;
		}
		if (bad)puts("-1");
		else {
			FF(i, n)printf("%d ", c[i]); puts("");
		}
		V.clear();
		FF(i, n) {
			for (int j = i + B; j; j /= 2)tr[j].clear();
			chk[i] = 0;
		}
	}

}