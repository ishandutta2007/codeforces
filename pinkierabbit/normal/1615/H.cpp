#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

namespace DinicFlows {
	const int Inf = 0x3f3f3f3f;
	const int MN = 1015, MM = 2005;
	
	int N, S, T;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], w[MM * 2], tot;
	
	inline void SetST(int _S, int _T) { S = _S, T = _T; }
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
		SetST(_N - 1, _N);
	}
	
	inline void ins(int u, int v, int x) {
		if (tot + 1 >= MM * 2) { puts("Error : too many edges."); return ; }
		nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot;
	}
	inline void insw(int u, int v, int w1 = Inf, int w2 = 0) {
		if (!u) u = S;
		if (!v) v = T;
		ins(u, v, w1), ins(v, u, w2);
	}
	
	int lv[MN], que[MN], l, r;
	
	inline bool Lvl() {
		for (int i = 1; i <= N; ++i) lv[i] = 0;
		lv[S] = 1;
		que[l = r = 1] = S;
		while (l <= r) {
			int u = que[l++];
			for (int i = h[u]; i; i = nxt[i])
				if (w[i] && !lv[to[i]]) {
					lv[to[i]] = lv[u] + 1;
					que[++r] = to[i];
				}
		}
		return lv[T] != 0;
	}
	
	int Flow(int u, int f) {
		if (u == T) return f;
		int d = 0, s = 0;
		for (int &i = iter[u]; i; i = nxt[i])
			if (w[i] && lv[to[i]] == lv[u] + 1) {
				d = Flow(to[i], std::min(f, w[i]));
				f -= d, s += d;
				w[i] -= d, w[i ^ 1] += d;
				if (!f) break;
			}
		return s;
	}
	
	inline int Dinic() {
		int Ans = 0;
		while (Lvl()) {
			for (int i = 1; i <= N; ++i) iter[i] = h[i];
			Ans += Flow(S, Inf);
		}
		return Ans;
	}
}

typedef pair<int, int> pii;
#define F(i, a, b) for(int i=a;i<=(b);++i)
#define F2(i, a, b) for(int i=a;i<(b);++i)
#define dF(i, a, b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 1005

int n, m, k;
int a[MN], s[MN], b[MN];
int eu[MM], ev[MM];
std::vector<int> G[MN];

void TaskSolve();

int main() {
	int tests = 1;
	while(tests--) {
		TaskSolve();
	}
	return 0;
}

int id[MN], iid[MN], tmp[MN];

void Solve(int lb, int rb, int l, int r) {
	if (l > r) return ;
	if (lb == rb) {
		F(i, l, r)
			b[id[i]] = s[lb];
		return ;
	}
	int mid = (lb + rb) >> 1;
	int len = r - l + 1;
	int lp = l, rp = r;
	{
		DinicFlows::Init(len + 2);
		F(i, l, r)
			for (int &v : G[id[i]])
				if (l <= iid[v] && iid[v] <= r)
					DinicFlows::insw(i - l + 1, iid[v] - l + 1);
		F(i, l, r) {
			if (a[id[i]] <= s[mid])
				DinicFlows::insw(0, i - l + 1, 1);
			else
				DinicFlows::insw(i - l + 1, 0, 1);
		}
		DinicFlows::Dinic();
	}
	F(i, l, r)
		if (DinicFlows::lv[i - l + 1])
			tmp[lp++] = id[i];
		else
			tmp[rp--] = id[i];
	F(i, l, r)
		iid[id[i] = tmp[i]] = i;
	Solve(lb, mid, l, rp);
	Solve(mid + 1, rb, lp, r);
}

void TaskSolve() {
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%d", a + i), s[i] = a[i];
	sort(s + 1, s + n + 1);
	k = unique(s + 1, s + n + 1) - s - 1;
	F(i, 1, m) {
		scanf("%d%d", &eu[i], &ev[i]);
		G[ev[i]].push_back(eu[i]);
	}
	F(i, 1, n) iid[id[i] = i] = i;
	Solve(1, k, 1, n);
	F(i, 1, n) printf("%d%c", b[i], " \n"[i == n]);
}