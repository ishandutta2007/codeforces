#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define fi first
#define se second
typedef long long LL;
typedef std::pair<int, int> pii;
const int MN = 500005, MM = 500005, MK = 500005;

int N, M, K, grp[MN], eu[MM], ev[MM];
std::map<pii, int> cntmp; int cnt;
std::vector<int> G[MN], V[MM];

int gg[MK], cntgg;
int col[MN], ccnt, chkbi;
void DFS(int u, int c) {
	col[u] = c;
	for (int v : G[u])
		if (!col[v]) DFS(v, c ^ 1);
		else if (col[v] == col[u]) chkbi = 0;
}

std::vector<int> G2[MN * 2];
int col2[MN * 2];
void DFS2(int u, int c) {
	col2[u] = c;
	for (int v : G2[u])
		if (!col2[v]) DFS2(v, c ^ 1);
		else if (col2[v] == col2[u]) chkbi = 0;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; ++i) scanf("%d", &grp[i]);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", &eu[i], &ev[i]);
		if (grp[eu[i]] == grp[ev[i]]) {
			G[eu[i]].push_back(ev[i]);
			G[ev[i]].push_back(eu[i]);
		} else {
			int gu = grp[eu[i]], gv = grp[ev[i]];
			if (gu > gv) std::swap(gu, gv), std::swap(eu[i], ev[i]);
			if (!cntmp.count({gu, gv})) cntmp[{gu, gv}] = ++cnt;
			V[cntmp[{gu, gv}]].push_back(i);
		}
	}
	ccnt = 1;
	for (int i = 1; i <= N; ++i) if (!col[i]) {
		ccnt += 2;
		chkbi = 1;
		DFS(i, ccnt);
		if (!chkbi) gg[grp[i]] = 1, ++cntgg;
	}
//	for (int i = 1; i <= N; ++i) printf("col[%d] = %d\n", i, col[i]);
	LL Ans = (LL)(K - cntgg) * (K - cntgg - 1) / 2;
	for (auto &pv : cntmp) {
		int gu = pv.fi.fi, gv = pv.fi.se, id = pv.se;
		if (gg[gu] || gg[gv]) continue;
		std::vector<int> seq;
		for (int e : V[id]) {
			int u = col[eu[e]], v = col[ev[e]];
			seq.push_back(u);
			seq.push_back(v);
			seq.push_back(u ^ 1);
			seq.push_back(v ^ 1);
			G2[u].push_back(v);
			G2[v].push_back(u);
			G2[u].push_back(u ^ 1);
			G2[u ^ 1].push_back(u);
			G2[v].push_back(v ^ 1);
			G2[v ^ 1].push_back(v);
		}
		chkbi = 1;
		for (int x : seq) if (!col2[x]) DFS2(x, 0);
		if (!chkbi) --Ans;
		for (int x : seq) {
			col2[x] = col2[x ^ 1] = 0;
			G2[x].clear(), G2[x].shrink_to_fit();
			G2[x ^ 1].clear(), G2[x ^ 1].shrink_to_fit();
		}
	}
	printf("%lld\n", Ans);
	return 0;
}