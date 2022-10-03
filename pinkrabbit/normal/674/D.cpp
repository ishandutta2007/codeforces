#include <cstdio>
#include <set>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005;

int N, Q, fl[MN], deg[MN];
LL wgh[MN], inc[MN];
std::multiset<LL> st0[MN], stmn, stmx;
inline LL MinVal(int i) { return st0[i].empty() ?  Infll : wgh[i] / deg[i] + *st0[i]. begin(); }
inline LL MaxVal(int i) { return st0[i].empty() ? -Infll : wgh[i] / deg[i] + *st0[i].rbegin(); }

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) scanf("%lld", &wgh[i]);
	for (int i = 1; i <= N; ++i) deg[i] = 2;
	for (int i = 1; i <= N; ++i) scanf("%d", &fl[i]), ++deg[fl[i]];
	for (int i = 1; i <= N; ++i) {
		LL val = wgh[i] / deg[i];
		inc[i] += wgh[i] - val * (deg[i] - 1);
		inc[fl[i]] += val;
	}
	for (int i = 1; i <= N; ++i) st0[fl[i]].insert(inc[i]);
	for (int i = 1; i <= N; ++i)
		stmn.insert(MinVal(i)),
		stmx.insert(MaxVal(i));
	while (Q--) {
		int op, x;
		scanf("%d", &op);
		if (op == 1) {
			int y, yy, yyy;
			scanf("%d%d", &x, &y), yy = fl[y], yyy = fl[yy];
			LL val = wgh[x] / deg[x];
			int u = fl[x], uu = fl[u], uuu = fl[uu];
			
			stmn.erase(stmn.find(MinVal(uuu)));
			stmx.erase(stmx.find(MaxVal(uuu)));
			st0[uuu].erase(st0[uuu].find(inc[uu]));
			inc[uu] -= wgh[u] / deg[u];
			stmn.erase(stmn.find(MinVal(uu)));
			stmx.erase(stmx.find(MaxVal(uu)));
			st0[uu].erase(st0[uu].find(inc[u]));
			inc[u] -= val;
			inc[u] -= wgh[u] - wgh[u] / deg[u] * (deg[u] - 1);
			stmn.erase(stmn.find(MinVal(u)));
			stmx.erase(stmx.find(MaxVal(u)));
			st0[u].erase(st0[u].find(inc[x]));
			--deg[u];
			stmn.insert(MinVal(u));
			stmx.insert(MaxVal(u));
			inc[u] += wgh[u] - wgh[u] / deg[u] * (deg[u] - 1);
			st0[uu].insert(inc[u]);
			stmn.insert(MinVal(uu));
			stmx.insert(MaxVal(uu));
			inc[uu] += wgh[u] / deg[u];
			st0[uuu].insert(inc[uu]);
			stmn.insert(MinVal(uuu));
			stmx.insert(MaxVal(uuu));
			
			stmn.erase(stmn.find(MinVal(yyy)));
			stmx.erase(stmx.find(MaxVal(yyy)));
			st0[yyy].erase(st0[yyy].find(inc[yy]));
			inc[yy] -= wgh[y] / deg[y];
			stmn.erase(stmn.find(MinVal(yy)));
			stmx.erase(stmx.find(MaxVal(yy)));
			st0[yy].erase(st0[yy].find(inc[y]));
			inc[y] += val;
			inc[y] -= wgh[y] - wgh[y] / deg[y] * (deg[y] - 1);
			stmn.erase(stmn.find(MinVal(y)));
			stmx.erase(stmx.find(MaxVal(y)));
			st0[y].insert(inc[x]);
			++deg[y];
			stmn.insert(MinVal(y));
			stmx.insert(MaxVal(y));
			inc[y] += wgh[y] - wgh[y] / deg[y] * (deg[y] - 1);
			st0[yy].insert(inc[y]);
			stmn.insert(MinVal(yy));
			stmx.insert(MaxVal(yy));
			inc[yy] += wgh[y] / deg[y];
			st0[yyy].insert(inc[yy]);
			stmn.insert(MinVal(yyy));
			stmx.insert(MaxVal(yyy));
			
			fl[x] = y;
		} else if (op == 2) {
			scanf("%d", &x);
			printf("%lld\n", inc[x] + wgh[fl[x]] / deg[fl[x]]);
		} else printf("%lld %lld\n", *stmn.begin(), *stmx.rbegin());
	}
	return 0;
}