#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>
#include <complex>
#include <string>

#define mul(x,y) ((ll)(x)*(y))%mod
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x),&(y))
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void bad() {
	puts("0");
	exit(0);
}

const int MN = 100000;

int cc[MN];
int ccn = 0;
int vis[MN];
int num[MN];

vector<pii> adj[MN];

void dfs(int i) {
	cc[i] = ccn;
	vis[i] = 1;
	for (auto &x : adj[i]) {
		if (vis[x.first]) {
			if (num[x.first] != x.second ^ num[i]) {
				bad();
			}
		}
		else {
			num[x.first] = num[i] ^ x.second;
			dfs(x.first);
		}
	}
}

const int mod = 1000000007;

int modpow(int n, int e) {
	if (!e)return 1;
	int tmp = modpow(n, e / 2);
	tmp = mul(tmp, tmp);
	if (e % 2)tmp = mul(tmp, n);
	return tmp;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; int tp;
		nii(u, v); ni(tp); u--; v--; tp = tp ^ 1;
		adj[u].push_back(mp(v, tp));
		adj[v].push_back(mp(u, tp));
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		num[i] = 0;
		dfs(i);
		ccn++;
	}

	printf("%d", modpow(2, ccn - 1));

	return 0;
}