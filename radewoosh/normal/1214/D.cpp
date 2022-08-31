//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n, m;

char wcz[nax];
vi tab[nax];

class LinkedList {
public:
	LinkedList(int N) : N(N), next(N) { clear(); }
	void clear() { head.assign(N, -1); }
	int front(int h) { return head[h]; }
	void pop(int h) { head[h] = next[head[h]]; }
	void push(int h, int u) { next[u] = head[h], head[h] = u; }
private:
	int N;
	vector<int> next, head;
};
class DoublyLinkedList {
private:
	struct Node { int prev, next; };
public:
	DoublyLinkedList(int N) : N(N), nodes(N) { clear(); }
	void clear() { head.assign(N, -1); }
	void erase(int h, int u) {
		int pv = nodes[u].prev, nx = nodes[u].next;
		if (nx >= 0) nodes[nx].prev = pv;
		if (pv >= 0) nodes[pv].next = nx;
		else head[h] = nx;
	}
	void insert(int h, int u) {
		nodes[u] = { -1, head[h]};
		if (head[h] >= 0) nodes[head[h]].prev = u;
		head[h] = u;
	}
	template <typename Func>
	void erase_all(int first, int last, Func f) {
		for (int i = first; i <= last; ++i) {
			for (int h = head[i]; h >= 0; h = nodes[h].next) f(h);
			head[i] = -1;
		}
	}
private:
	int N;
	vector<int> head;
	vector<Node> nodes;
};
template <
    typename CapType, typename TotalCapType,
    bool UseGlobal = true, bool UseGap = true
    >
class HighestLabelPushRelabel {
private:
	TotalCapType inf = pow(10., sizeof(TotalCapType) / 4 * 9);
	struct Edge { int to, rev; CapType cap; };
public:
	HighestLabelPushRelabel(int N) : N(N), E(0), G(N), que(N), list(N), dlist(N) {}
	TotalCapType maximum_flow(int s, int t) {
		if (s == t) return 0;
		highest_active = 0; // highest label (active)
		highest = 0; // highest label (active and inactive)
		height.assign(N, 0); height[s] = N;
		for (int i = 0; i < N; ++i) if (i != s) dlist.insert(height[i], i);
		count.assign(N, 0); count[0] = N - 1;
		excess.assign(N, 0); excess[s] = inf; excess[t] = -inf;
		for (auto& e : G[s]) push(s, e);
		global_relabel(t);
		for (int u = -1, rest = N; highest_active >= 0; ) {
			if ((u = list.front(highest_active)) < 0) { --highest_active; continue; }
			list.pop(highest_active);
			discharge(u);
			if (--rest == 0) rest = N, global_relabel(t);
		}
		return excess[t] + inf;
	}
	inline void add_directed_edge(int u, int v, CapType cap) {
		debug() << u << " " << v;
		E++;
		G[u].push_back({v, (int) G[v].size(), cap});
		G[v].push_back({u, (int) G[u].size() - 1, 0});
	}
	inline void add_undirected_edge(int u, int v, CapType cap) {
		G[u].push_back({v, (int) G[v].size(), cap});
		G[v].push_back({u, (int) G[u].size() - 1, cap});
	}
private:
	void global_relabel(int t) {
		if (!UseGlobal) return;
		height.assign(N, N); height[t] = 0;
		count.assign(N, 0);
		int qh = 0, qt = 0;
		for (que[qt++] = t; qh < qt; ) {
			int u = que[qh++], h = height[u] + 1;
			for (auto& e : G[u]) if (height[e.to] == N && G[e.to][e.rev].cap > 0) {
					count[height[e.to] = h] += 1;
					que[qt++] = e.to;
				}
		}
		list.clear(); dlist.clear();
		for (int u = 0; u < N; ++u) if (height[u] < N) {
				dlist.insert(height[u], u);
				if (excess[u] > 0) list.push(height[u], u);
			}
		highest = highest_active = height[que[qt - 1]];
	}
	void push(int u, Edge& e) {
		int v = e.to;
		CapType df = min(excess[u], TotalCapType(e.cap));
		e.cap -= df, G[v][e.rev].cap += df;
		excess[u] -= df, excess[v] += df;
		if (0 < excess[v] && excess[v] <= df) list.push(height[v], v);
	}
	void discharge(int u) {
		int nh = N;
		for (auto& e : G[u]) if (e.cap > 0) {
				if (height[u] == height[e.to] + 1) {
					push(u, e);
					if (excess[u] == 0) return;
				} else nh = min(nh, height[e.to] + 1);
			}
		int h = height[u];
		if (UseGap && count[h] == 1) {
			auto f = [&] (int u) { count[height[u]]--, height[u] = N; };
			dlist.erase_all(h, highest, f);
			highest = h - 1;
		} else {
			count[h]--; dlist.erase(h, u);
			height[u] = nh;
			if (nh == N) return;
			count[nh]++; dlist.insert(nh, u);
			highest = max(highest, highest_active = nh);
			list.push(nh, u);
		}
	}
	int N, E, highest_active, highest;
	vector< vector<Edge> > G;
	vector<int> height, count, que;
	vector<TotalCapType> excess;
	LinkedList list;
	DoublyLinkedList dlist;
};
using HIPR_GP = HighestLabelPushRelabel<int, int, true, true>;


int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
			tab[i-1].push_back(wcz[j]=='#');
	}
	HIPR_GP janusz=HIPR_GP(n*m*2);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			int x=(i*m+j)*2;
			if (!tab[i][j])
				janusz.add_directed_edge(x, x+1, 1);
		}
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			int x=(i*m+j)*2;
			if (j+1<m)
				janusz.add_directed_edge(x+1, x+2, 1);
			if (i+1<n)
				janusz.add_directed_edge(x+1, ((i+1)*m+j)*2, 1);
		}
	}
	printf("%d\n", janusz.maximum_flow(1, 2*n*m-2));
	return 0;
}