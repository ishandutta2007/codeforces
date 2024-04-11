#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string.h>
#define mp(a,b) make_pair(a,b)
#define ni(a) scanf("%d", &(a))
#define F(i,n) for(int (i) = 0; (i) < (n); (i)++)

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, piii> piiii;

const int MN = 100000;
int dcnt = 0;

vector<int> adj[MN];
int rnk[MN];
int anc[MN][17];
int vis[MN];
int dfsnum[MN];
int _using[MN];
int mark[MN];
int mark2[MN];

int goup(int x, int dif) {
	int LOG = 16;
	while (LOG >= 0) {
		if (dif >= (1 << LOG)) {
			dif -= (1 << LOG);

			x = anc[x][LOG];
		}
		LOG--;
	}
	return x;
}

int lca(int x, int y) {
	if (rnk[x] < rnk[y]) swap(x, y);
	int dr = rnk[x] - rnk[y];
	x = goup(x, dr);
	if (x == y) return x;
	int LOG = 16;
	while (LOG >= 0) {
		if (anc[x][LOG] != anc[y][LOG]) {
			x = anc[x][LOG];
			y = anc[y][LOG];
		}
		LOG--;
	}
	return anc[x][0];
}

void dfs(int i) {
	vis[i] = 1;
	dfsnum[i] = dcnt++;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		dfs(x);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	ni(n);
	F(i, n - 1) {
		int u, v; ni(u); ni(v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> qu;
	vis[0] = 1;
	rnk[0] = 0;
	anc[0][0] = -1;
	qu.push(0);
	while (!qu.empty()) {
		int x = qu.front(); qu.pop();
		for (auto &y : adj[x]) {
			if (vis[y]) continue;
			vis[y] = 1;
			rnk[y] = rnk[x] + 1;
			anc[y][0] = x;
			qu.push(y);
		}
	}
	for (int i = 1; i <= 16; i++) {
		F(j, n) {
			int a = anc[j][i - 1];
			if (a == -1) anc[j][i] = -1;
			else {
				anc[j][i] = anc[a][i - 1];
			}
		}
	}
	auto cmp = [&](const int &x, const int &y)->bool {return dfsnum[x] < dfsnum[y]; };
	memset(vis, 0, sizeof(vis));
	dfs(0);
	int q; ni(q);
	F(jj, q) {
		int ki; ni(ki);
		set<int, decltype(cmp)> sorted(cmp);
		F(i, ki) {
			int s; ni(s);
			sorted.insert(s - 1);
			_using[s - 1] = jj + 1;
		}
		int cnt = 0;
		priority_queue<piiii> pq; int st = 0; int sv;
		for (auto &x : sorted) {
			if (!st) {
				sv = x;
				st = 1; continue;
			}
			int l = lca(sv, x);
			pq.push(mp(rnk[l], mp(l, mp(sv, x))));
			sv = x;
		}
		int bad = 0;
		while (!pq.empty()) {
			auto x = pq.top(); pq.pop();
			if (mark2[x.second.second.first] == jj + 1 || mark2[x.second.second.second] == jj + 1) continue;
			if (_using[x.second.first] == jj + 1) {
				if (x.second.first == x.second.second.second) {
					int dd = rnk[x.second.second.first] - x.first;
					if (dd == 1) {
						bad = 1;
						puts("-1");
						break;
					}
					int yy = goup(x.second.second.first, dd - 1);
					if (mark[yy] != jj + 1) {
						cnt++;
						mark[yy] = jj + 1;
					}
					if (dfsnum[x.second.first] < dfsnum[x.second.second.first]) {
						auto it = sorted.find(x.second.second.first);
						it++;
						mark2[x.second.second.first] = jj + 1;
						if (it != sorted.end()) {
							auto hh = *it;
							int l = lca(x.second.first, hh);
							pq.push(mp(rnk[l], mp(l, mp(x.second.first, hh))));
						}
						sorted.erase(x.second.second.first);
					}
					else {
						auto it = sorted.find(x.second.second.first);
						mark2[x.second.second.first] = jj + 1;
						if (it != sorted.begin()) {
							it--;
							int hh = *it;
							int l = lca(hh, x.second.first);
							pq.push(mp(rnk[l], mp(l, mp(hh, x.second.first))));
						}
						sorted.erase(x.second.second.first);
					}
				}
				else if (x.second.first == x.second.second.first) {
					int dd = rnk[x.second.second.second] - x.first;
					if (dd == 1) {
						bad = 1;
						puts("-1");
						break;
					}
					int yy = goup(x.second.second.second, dd - 1);
					if (mark[yy] != jj + 1) {
						cnt++;
						mark[yy] = jj + 1;
					}
					if (dfsnum[x.second.first] < dfsnum[x.second.second.second]) {
						auto it = sorted.find(x.second.second.second);
						it++;
						mark2[x.second.second.second] = jj + 1;
						if (it != sorted.end()) {
							auto hh = *it;
							int l = lca(x.second.first, hh);
							pq.push(mp(rnk[l], mp(l, mp(x.second.first, hh))));
						}
						sorted.erase(x.second.second.second);
					}
					else {
						auto it = sorted.find(x.second.second.second);
						mark2[x.second.second.second] = jj + 1;
						if (it != sorted.begin()) {
							it--;
							int hh = *it;
							int l = lca(hh, x.second.first);
							pq.push(mp(rnk[l], mp(l, mp(hh, x.second.first))));
						}
						sorted.erase(x.second.second.second);
					}
				}
				else {
					int da = rnk[x.second.second.first] - rnk[x.second.first];
					int db = rnk[x.second.second.second] - rnk[x.second.first];
					if (da == 1 || db == 1) {
						bad = 1;
						puts("-1");
						break;
					}
					int aa = goup(x.second.second.first, da - 1);
					int bb = goup(x.second.second.second, db - 1);
					if (mark[aa] != jj + 1) {
						cnt++;
						mark[aa] = jj + 1;
					}
					if (mark[bb] != jj + 1) {
						cnt++;
						mark[bb] = jj + 1;
					}
					auto it1 = sorted.find(x.second.second.first);
					if (it1 != sorted.begin()) {
						it1--;
						int xx = *it1;
						auto it2 = sorted.find(x.second.second.second);
						it2++;
						if (it2 != sorted.end()) {
							int yy = *it2;
							int l = lca(xx, yy);
							pq.push(mp(rnk[l], mp(l, mp(xx, yy))));
						}
					}
					mark2[x.second.second.first] = jj + 1;
					mark2[x.second.second.second] = jj + 1;
					sorted.erase(x.second.second.first);
					sorted.erase(x.second.second.second);
				}
			}
			else {
				if (mark[x.second.first] != jj + 1) {
					cnt++;
					mark[x.second.first] = jj + 1;
				}
				auto it1 = sorted.find(x.second.second.first);
				auto it2 = sorted.find(x.second.second.second);
				for (; it2 != sorted.end();) {
					if (lca(x.second.second.first, *it2) == x.second.first) {
						mark2[*it2] = jj + 1;
						it2 = sorted.erase(it2);
					}
					else break;
				}
				for (; it1 != sorted.begin();) {
					it1--;
					if (lca(x.second.second.first, *it1) == x.second.first) {
						mark2[*it1] = jj + 1;
						it1 = sorted.erase(it1);
					}
					else {
						it1++;
						break;
					}
				}
				if (it1 != sorted.begin()) {
					it1--;
					int xx = *it1;
					
					if (it2 != sorted.end()) {
						int yy = *it2;
						int l = lca(xx, yy);
						pq.push(mp(rnk[l], mp(l, mp(xx, yy))));
					}
				}
				mark2[x.second.second.first] = jj + 1;
				sorted.erase(x.second.second.first);
			}
		}
		if (bad) continue;
		printf("%d\n", cnt);
	}
	return 0;
}