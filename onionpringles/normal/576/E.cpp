#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define mp(a,b) make_pair((a),(b))
#define save(a,x) (a).push_back(mp(&(x),(x)))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int*, int> ppii;

const int B = 524288;
const int M = 500000;

int par[50][M];
int ban[50][M];
int rnk[50][M];
vector<pii> tr[2 * B];
vector<ppii> hist[2 * B];

//queries
vector<int> qped[M];
int qe[M];
int qc[M];

//edge info
int eu[M];
int ev[M];
int curcl[M];

//qped iterator
int it[M];
int q;
void push(int nd, int ndl, int ndr, int l, int r, int val1, int val2) {
	if (l > r) return;
	if (ndl > r || ndr < l) return;
	if (l <= ndl && ndr <= r) {
		tr[nd].push_back(mp(val1, val2));
		return;
	}
	int mid = (ndl + ndr) / 2;
	push(2 * nd, ndl, mid, l, r, val1, val2);
	push(2 * nd + 1, mid + 1, ndr, l, r, val1, val2);
	return;
}

void push(int l, int r, int val1, int val2) {
	push(1, 0, B - 1, l, r, val1, val2);
}

int find(int k, int i) {
	while (par[k][i] != -1) {
		i = par[k][i];
	}
	return i;
}

int merge(int k, int i, int j, vector<ppii> &a) {
	i = find(k, i);
	j = find(k, j);
	if (i == j) return 0;
	if (ban[k][i] == j) return 1;
	int bi = ban[k][i];
	int bj = ban[k][j];
	if (bi == -1) {
		if (bj == -1) {
			save(a, ban[k][i]);
			save(a, ban[k][j]);
			ban[k][i] = j;
			ban[k][j] = i;
		}
		else {
			if (rnk[k][i] < rnk[k][bj]) {
				save(a, par[k][i]);
				par[k][i] = bj;
			}
			else {
				save(a, par[k][bj]);
				save(a, ban[k][i]);
				save(a, ban[k][j]);
				par[k][bj] = i;
				ban[k][i] = j;
				ban[k][j] = i;
				if (rnk[k][i] == rnk[k][bj]) {
					save(a, rnk[k][i]);
					rnk[k][i]++;
				}
			}
		}
	}
	else {
		if (bj == -1) {
			if (rnk[k][bi] < rnk[k][j]) {
				save(a, par[k][bi]);
				save(a, ban[k][i]);
				save(a, ban[k][i]);
				par[k][bi] = j;
				ban[k][j] = i;
				ban[k][i] = j;
			}
			else {
				save(a, par[k][j]);
				par[k][j] = bi;
				if (rnk[k][bi] == rnk[k][j]) {
					save(a, rnk[k][bi]);
					rnk[k][bi]++;
				}
			}
		}
		else {
			int parx, pary;
			if (rnk[k][bi] < rnk[k][j]) {
				save(a, par[k][bi]);
				par[k][bi] = j;
				parx = j;
			}
			else {
				save(a, par[k][j]);
				par[k][j] = bi;
				parx = bi;
				if (rnk[k][bi] == rnk[k][j]) {
					save(a, rnk[k][bi]);
					rnk[k][bi]++;
				}
			}

			if (rnk[k][i] < rnk[k][bj]) {
				save(a, par[k][i]);
				par[k][i] = bj;
				pary = bj;
			}
			else {
				save(a, par[k][bj]);
				par[k][bj] = i;
				pary = i;
				if (rnk[k][i] == rnk[k][bj]) {
					save(a, rnk[k][i]);
					rnk[k][i]++;
				}
			}
			save(a, ban[k][parx]);
			save(a, ban[k][pary]);
			ban[k][parx] = pary;
			ban[k][pary] = parx;
		}
	}
	return 1;
}

void pophist(vector<ppii> &a) {
	while (!a.empty()) {
		int* x = a.back().first;
		int y = a.back().second;
		*x = y;
		a.pop_back();
	}
	return;
}

void dfs(int i) {
	for (auto &q : tr[i]) {
		int k = q.first;
		int e = q.second;
		int u = eu[e];
		int v = ev[e];
		merge(k, u, v, hist[i]);
	}
	tr[i] = vector<pii>();
	if (i < B) {
		dfs(2 * i);
		dfs(2 * i + 1);
	}
	else {
		if (i - B >= q) {
			exit(0);
		}
		int qnum = i - B;
		int k = qc[qnum];
		int e = qe[qnum];
		int u = eu[e];
		int v = ev[e];
		if (merge(k, u, v, hist[i])) {
			puts("YES");
			int r = ++it[e];
			if (r == qped[e].size()) {
				push(qnum + 1, B - 1, k, e);
			}
			else {
				int nx = qped[e][r];
				push(qnum + 1, nx - 1, k, e);
			}
			curcl[e] = k;
		}
		else {
			puts("NO");
			int r = ++it[e];
			k = curcl[e];
			if (k >= 0) {
				if (r == qped[e].size()) {
					push(qnum + 1, B - 1, k, e);
				}
				else {
					int nx = qped[e][r];
					push(qnum + 1, nx - 1, k, e);
				}
			}
		}
	}
	pophist(hist[i]);
	hist[i] = vector<ppii>();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < M; j++) {
			par[i][j] = -1;
			ban[i][j] = -1;
		}
	}

	int n, m, k;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u,&v);
		u--; v--;
		eu[i] = u;
		ev[i] = v;
		curcl[i] = -1;
	}
	for (int i = 0; i < q; i++) {
		int e, c;
		scanf("%d %d", &e, &c);
		e--; c--;
		qe[i] = e;
		qc[i] = c;
		qped[e].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		sort(qped[i].begin(), qped[i].end());
	}
	dfs(1);
	return 0;
}