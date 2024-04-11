#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <tuple>

#define mp make_pair
#define mtp make_tuple
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))
#define fi get<0>
#define sc get<1>
#define th get<2>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 500000;

int par[MN];
int parcnt[MN];
pii raid[MN];
int chcnt[MN];
int rootl[MN];
int rnk[MN];
ll cnt[MN];
tuple<char, int, int> queries[MN];
long long prevans[MN];
vector<pair<int, int> > raidquery;

ll count(int nd) {
	ll ans = 0;
	while (nd != -1) {
		ans += cnt[nd];
		nd = par[nd];
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	nii(n, m);
	for (int i = 0; i < n; i++) {
		par[i] = -1;
		rootl[i] = i;
		raid[i].first = -1;
	}

	for (int i = 0; i < m; i++) {
		char tp;
		scanf(" %c", &tp);
		fi(queries[i]) = tp;
		if (tp == 'U') {
			int a, b;
			nii(a, b);
			a--; b--;
			sc(queries[i]) = a;
			th(queries[i]) = b;
		}
		else if (tp == 'M') {
			int c, d;
			nii(c, d);
			c--; d--;
			int cr = rootl[c];
			int dr = rootl[d];
			if (rnk[cr] < rnk[dr]) {
				par[cr] = dr;
				parcnt[cr] = chcnt[dr];
				chcnt[dr]++;
				rootl[c] = dr;
			}
			else {
				par[dr] = cr;
				parcnt[dr] = chcnt[cr];
				chcnt[cr]++;
				if (rnk[cr] == rnk[dr]) rnk[cr]++;
			}
		}
		else if (tp == 'A') {
			int x;
			ni(x); x--;
			sc(queries[i]) = x;
		}
		else if (tp == 'Z') {
			int y;
			ni(y); y--;
			int ry = rootl[y];
			raid[ry] = mp(chcnt[ry], i);
		}
		else {
			int q;
			ni(q);
			q--;
			int mx = -1; int cur = q; int curcnt = -1;
			while (cur != -1) {
				if (raid[cur].first > curcnt) {
					mx = raid[cur].second;
				}
				curcnt = parcnt[cur];
				cur = par[cur];
			}
			sc(queries[i]) = q;
			if (mx >= 0) raidquery.push_back(mp(mx, i));
		}
	}
	sort(raidquery.begin(), raidquery.end());

	auto it = raidquery.begin();
	for (int i = 0; i < n; i++) {
		par[i] = -1; rootl[i] = i;
		rnk[i] = 1; cnt[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		char tp = fi(queries[i]);
		if (tp == 'U') {
			int a = sc(queries[i]);
			int b = th(queries[i]);
			int ra = rootl[a];
			int rb = rootl[b];
			if (rnk[ra] < rnk[rb]) {
				par[ra] = rb;
				cnt[ra] -= cnt[rb];
				rnk[rb] += rnk[ra];
				rootl[a] = rb;
			}
			else {
				par[rb] = ra;
				cnt[rb] -= cnt[ra];
				rnk[ra] += rnk[rb];
			}
		}
		else if (tp == 'M') {
			
		}
		else if (tp == 'A') {
			int x = sc(queries[i]);
			int rx = rootl[x];
			cnt[rx] += rnk[rx];
		}
		else if (tp == 'Z') {
			for (; it != raidquery.end(); it++) {
				if (it->first != i) break;
				int tm = it->second;
				int nd = sc(queries[tm]);
				ll res = count(nd);
				prevans[tm] = res;
			}
		}
		else {
			int nd = sc(queries[i]);
			ll res = count(nd);
			printf("%I64d\n", res - prevans[i]);
		}
	}
	return 0;
}