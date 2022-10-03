#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 50005, MM = 50005;

int N, M, eu[MM], ev[MM], ec[MM], et[MM], Cnt, mxt;
std::vector<int> G[MN], _H[MM * 6]; const auto H = _H + MM * 3;

inline void ins(int x, int y) { H[x].push_back(y); }
inline void insw(int x, int y) { ins(x, y), ins(-y, -x); }

int stk[MM * 6], top;
int _instk[MM * 6], _bel[MM * 6], _dfn[MM * 6], _low[MM * 6], dfc, scnt;
const auto instk = _instk + MM * 3, bel = _bel + MM * 3, dfn = _dfn + MM * 3, low = _low + MM * 3;
void Tarjan(int u) {
	instk[stk[++top] = u] = 1;
	low[u] = dfn[u] = ++dfc;
	for (auto v : H[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (instk[v]) low[u] = std::min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++scnt;
		for (int x = 0; x != u; --top) {
			bel[x = stk[top]] = scnt;
			instk[x] = 0;
		}
	}
}

inline bool chk(int mid) {
	for (int i = 1; i <= M; ++i) if (et[i] > mid) ins(i, -i);
	scnt = dfc = 0;
	for (int i = 1; i <= Cnt; ++i) dfn[i] = dfn[-i] = 0;
	for (int i = 1; i <= Cnt; ++i) {
		if (!dfn[i]) Tarjan(i);
		if (!dfn[-i]) Tarjan(-i);
	}
	bool ans = 1;
	for (int i = 1; i <= M; ++i) if (bel[i] == bel[-i]) ans = 0;
	for (int i = 1; i <= M; ++i) if (et[i] > mid) H[i].pop_back();
	return ans;
}

int main() {
	scanf("%d%d", &N, &M), Cnt = M;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d%d", &eu[i], &ev[i], &ec[i], &et[i]);
		G[eu[i]].push_back(i);
		G[ev[i]].push_back(i);
		mxt = std::max(mxt, et[i]);
	}
	for (int u = 1; u <= N; ++u) {
		std::sort(G[u].begin(), G[u].end(), [&](int i, int j) {
			return ec[i] < ec[j];
		});
		int lst = 0, cnt = 0, e1 = 0, e2 = 0;
		for (auto i : G[u]) {
			if (ec[i] == ec[lst]) ++cnt, e1 = lst, e2 = i;
			lst = i;
		}
		if (cnt >= 2) return puts("No"), 0;
		if (cnt) {
			insw(e1, -e2), insw(-e1, e2);
			for (auto i : G[u])
				if (i != e1 && i != e2) ins(i, -i);
		} else {
			lst = 0;
			for (auto i : G[u]) {
				insw(i, ++Cnt);
				if (lst)
					insw(lst, Cnt),
					insw(lst, -i);
				lst = Cnt;
			}
		}
	}
	int lb = 0, rb = mxt, mid, ans = -1;
	while (lb <= rb) {
		mid = (lb + rb) / 2;
		if (chk(mid)) ans = mid, rb = mid - 1;
		else lb = mid + 1;
	}
	if (ans == -1) return puts("No"), 0;
	puts("Yes");
	chk(ans);
	int ansc = 0;
	for (int i = 1; i <= M; ++i)
		if (bel[i] < bel[-i]) ++ansc;
	printf("%d %d\n", ans, ansc);
	for (int i = 1; i <= M; ++i)
		if (bel[i] < bel[-i]) printf("%d%c", i, " \n"[--ansc == 0]);
	return 0;
}