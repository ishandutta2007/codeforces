#include <cstdio>
#include <vector>
#include <queue>
#include <set>

#define pb push_back
#define mp std::make_pair
#define fi first
#define se second
typedef long long LL;
typedef std::pair<LL, int> pli;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005;
const int MM = 100005;
const int MS = 1 << 18 | 7;

int N, M, S;
int typ[MM], ex[MM], ey[MM], ez[MM], ew[MM], vis[MM];
std::vector<int> V[MN], seg[MS];
std::priority_queue<pli> pq;
std::set<int> st;
LL dis[MN];

void Ins(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) { seg[i].push_back(x); return ; }
	Ins(i << 1, l, (l + r) >> 1, a, b, x);
	Ins(i << 1 | 1, ((l + r) >> 1) + 1, r, a, b, x);
}

void Push(int i, int l, int r, int p) {
	for (auto j : seg[i]) if (!vis[j])
		pq.push(mp(-dis[p] - ew[j], j)), vis[j] = 1;
	seg[i].clear();
	if (l == r) return ;
	int mid = (l + r) >> 1;
	if (p <= mid) Push(i << 1, l, mid, p);
	else Push(i << 1 | 1, mid + 1, r, p);
}

inline void Del(int u) {
	for (auto i : V[u]) pq.push(mp(-dis[u] - ew[i], i));
	Push(1, 1, N, u);
}

int main() {
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d", &typ[i], &ex[i], &ey[i]);
		if (typ[i] != 1) scanf("%d", &ez[i]);
		else ez[i] = ey[i];
		scanf("%d", &ew[i]);
		if (typ[i] != 3) V[ex[i]].pb(i);
		else Ins(1, 1, N, ey[i], ez[i], i);
	}
	for (int i = 1; i <= N; ++i) {
		dis[i] = Infll;
		st.insert(i);
	}
	dis[S] = 0, Del(S), st.erase(S);
	while (!pq.empty()) {
		pli p = pq.top(); pq.pop();
		LL d = -p.fi;
		int id = p.se, lb, rb;
		if (typ[id] == 3) lb = rb = ex[id];
		else lb = ey[id], rb = ez[id];
		auto it = st.lower_bound(lb);
		while (it != st.end() && *it <= rb)
			dis[*it] = d, Del(*it), it = st.erase(it);
	}
	for (int i = 1; i <= N; ++i)
		printf("%lld ", dis[i] == Infll ? -1 : dis[i]);
	return 0;
}