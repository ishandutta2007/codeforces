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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 300000;

set<int> adj[N];
int par[N];
int cnt[N];
int find(int x) {
	if (x != par[x]) par[x] = find(par[x]);
	return par[x];
}

set<int> rtlist;
int ind[N];
vector<int> part[1000];

void merge(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j) return;
	if (cnt[i] < cnt[j]) {
		par[i] = j;
		cnt[j] += cnt[i];
		rtlist.erase(i);
	}
	else {
		par[j] = i;
		cnt[i] += cnt[j];
		rtlist.erase(j);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, k; nii(n, m); ni(k);
	for (int i = 0; i < n; i++) {
		cnt[i] = 1;
		par[i] = i;
	}
	for (int i = 1; i < n; i++) {
		rtlist.insert(i);
	}
	for (int i = 0; i < m; i++) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for (int i = 1; i < n; i++) {
		map<int, int> tmpadj;
		for (auto &x : adj[i]) {
			tmpadj[find(x)]++;
		}
		for (auto it = tmpadj.begin(); it != tmpadj.end();) {
			int cc = it->second;
			if (cc < cnt[it->first]) {
				it = tmpadj.erase(it);
				continue;
			}
			it++;
		}
		auto it = rtlist.begin();
		vector<int> tom;
		for (auto &x : tmpadj) {
			while (*it < x.first) {
				tom.push_back(*it);
				it++;
			}
			it++;
		}
		while (it != rtlist.end()) {
			tom.push_back(*it);
			it++;
		}
		for (auto &x : tom) {
			merge(i, x);
		}
	}
	int  jj = 0;
	for (auto &x : rtlist) ind[x] = jj++;
	for (int i = 1; i < n; i++) {
		int hh = find(i);
		hh = ind[hh];
		part[hh].push_back(i);
	}
	if (rtlist.size() > k) {
		puts("impossible");
		return 0;
	}
	if (adj[0].size() + k > n - 1) {
		puts("impossible");
		return 0;
	}
	for (auto &x : rtlist) {
		int ii = ind[x];
		int good = 0;
		for (auto &y : part[ii]) {
			if (adj[0].find(y) == adj[0].end()) {
				good = 1;
				break;
			}
		}
		if (!good) {
			puts("impossible");
			return 0;
		}
	}
	puts("possible");
	return 0;
}