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
#include <queue>

#define mul(x,y) ((ll)(x)*(y))%mod
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x),&(y))
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 100000;

class Bunsu {
public:
	int num; int denom;
	Bunsu() {}
	Bunsu(int _x, int _y) :num(_x), denom(_y) {}
	bool operator<(const Bunsu& ot) const{
		return (ll)num*ot.denom > (ll)ot.num*denom;
	}
};

vector<int> ans;
int vis[MN];
int cnt[MN];
int bad[MN];
vector<int> adj[MN];
priority_queue<pair<Bunsu, int> > pq;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	nii(n, m); ni(k);
	for (int i = 0; i < k; i++) {
		int x;
		ni(x);
		bad[x - 1] = 1;
	}
	Bunsu curmin = Bunsu(1,1);
	for (int i = 0; i < m; i++) {
		int u, v;
		nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (bad[i]) continue;
		for (auto &x : adj[i]) {
			if (bad[x]) continue;
			cnt[i]++;
		}
		Bunsu tmp = Bunsu(cnt[i], adj[i].size());
		curmin = max(curmin, tmp);
		pq.push(mp(tmp, i));
	}
	int curind = 0;
	int j = 0;
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		if (vis[x.second]) continue;
		vis[x.second] = 1;
		j++;
		for (auto &y : adj[x.second]) {
			if (bad[y] || vis[y]) continue;
			cnt[y]--;
			Bunsu tmp = Bunsu(cnt[y], adj[y].size());
			pq.push(mp(tmp, y));
		}
		while (!pq.empty()) {
			auto x = pq.top();
			if (!vis[x.second]) break;
			else {
				pq.pop();
			}
		}
		if (!pq.empty()) {
			auto x = pq.top();
			if (x.first < curmin) {
				curind = j;
				curmin = x.first;
			}
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		if (bad[i]) continue;
		for (auto &x : adj[i]) {
			if (bad[x]) continue;
			cnt[i]++;
		}
		Bunsu tmp = Bunsu(cnt[i], adj[i].size());
		pq.push(mp(tmp, i));
	}
	j = 0;
	memset(vis, 0, sizeof(vis));
	while (!pq.empty()) {
		if (j == curind) break;
		auto x = pq.top(); pq.pop();
		if (vis[x.second]) continue;
		vis[x.second] = 1;
		j++;
		for (auto &y : adj[x.second]) {
			if (bad[y] || vis[y]) continue;
			cnt[y]--;
			Bunsu tmp = Bunsu(cnt[y], adj[y].size());
			pq.push(mp(tmp, y));
		}
	}
	int ccc = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i] && !bad[i]) {
			ans.push_back(i);
			ccc++;
		}
	}
	printf("%d\n", ccc);
	for (auto &x : ans) {
		printf("%d ", x + 1);
	}
	return 0;
}