#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <unordered_map>
#include <cstring>
#include <numeric>
#include <queue>
#include <random>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "movetofront"

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)1e5 + 7;
const ll inf = (ll)1e18 + 7;

struct edge {
	int l, r, w;
};
struct st {
	int v, w;
} R[dd];
int cnt;

vector<edge> G[dd];
vector<int> T_edge[4 * dd];
int used_edge[dd], n;
ll val;

struct node {
	ll M, psh;
	int pos, f;
} T[4 * dd];

void build_Min(int v, int tl, int tr) {
	T[v] = { inf, inf, tl, 1 };
	if (tl != tr) {
		int tm = (tl + tr) / 2;
		build_Min(v * 2, tl, tm);
		build_Min(v * 2 + 1, tm + 1, tr);
	}
}

void uin(ll &a, ll b) {
	if (a > b) a = b;
}

void push(int v, int tl, int tr) {
	if (T[v].psh == inf) return;
	uin(T[v].M, T[v].psh);
	if (tl != tr) {
		if (T[v * 2].f) uin(T[v * 2].psh, T[v].psh);
		if (T[v * 2 + 1].f) uin(T[v * 2 + 1].psh, T[v].psh);
	}
	T[v].psh = inf;
}

void upd_Min(int v, int tl, int tr, int l, int r, ll val) {
	push(v, tl, tr);
	if (tl == l && tr == r) {
		if (T[v].f) uin(T[v].psh, val);
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) / 2;
		if (r <= tm)
			upd_Min(v * 2, tl, tm, l, r, val);
		else if (l > tm)
			upd_Min(v * 2 + 1, tm + 1, tr, l, r, val);
		else
			upd_Min(v * 2, tl, tm, l, tm, val), upd_Min(v * 2 + 1, tm + 1, tr, tm + 1, r, val);
		push(v * 2, tl, tm), push(v * 2 + 1, tm + 1, tr);
		if (T[v].f) if ((T[v * 2].M <= T[v * 2 + 1].M || !T[v * 2 + 1].f) && T[v * 2].f)
			T[v].M = T[v * 2].M, T[v].pos = T[v * 2].pos;
		else
			T[v].M = T[v * 2 + 1].M, T[v].pos = T[v * 2 + 1].pos;
	}
}

void add_edge(int v, int tl, int tr, int l, int r, int val) {
	if (tl == l && tr == r)
		T_edge[v].push_back(val);
	else {
		int tm = (tl + tr) / 2;
		if (r <= tm)
			add_edge(v * 2, tl, tm, l, r, val);
		else if (l > tm)
			add_edge(v * 2 + 1, tm + 1, tr, l, r, val);
		else
			add_edge(v * 2, tl, tm, l, tm, val), add_edge(v * 2 + 1, tm + 1, tr, tm + 1, r, val);
	}
}

void not_used(int v, int tl, int tr, int pos) {
	push(v, tl, tr);
	if (tl == tr)
		T[v].f = 0;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			not_used(v * 2, tl, tm, pos);
		else 
			not_used(v * 2 + 1, tm + 1, tr, pos);
		push(v * 2, tl, tm), push(v * 2 + 1, tm + 1, tr);
		if (!T[v * 2].f && !T[v * 2 + 1].f)
			T[v].f = 0;
		if (T[v].f) if ((T[v * 2].M <= T[v * 2 + 1].M || !T[v * 2 + 1].f) && T[v * 2].f)
			T[v].M = T[v * 2].M, T[v].pos = T[v * 2].pos;
		else
			T[v].M = T[v * 2 + 1].M, T[v].pos = T[v * 2 + 1].pos;
	}
}

pair<ll, int> get_Min() {
	push(1, 0, n - 1);
	return{ T[1].M, T[1].pos };
}

void go_upd(int v, int tl, int tr, int pos) {
	while ((int)T_edge[v].size()) {
		if (!used_edge[T_edge[v].back()]) {
			upd_Min(1, 0, n - 1, R[T_edge[v].back()].v, R[T_edge[v].back()].v, val + R[T_edge[v].back()].w);
			used_edge[T_edge[v].back()] = 1;
		}
		T_edge[v].pop_back();
	}
	
	if (tl != tr) {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			go_upd(v * 2, tl, tm, pos);
		else
			go_upd(v * 2 + 1, tm + 1, tr, pos);
	}
}

void go_Min(int v, int tl, int tr) {
	if (tl == tr)
		printf("%I64d ", T[v].f ? -1ll : T[v].M);
	else {
		int tm = (tl + tr) / 2;
		go_Min(v * 2, tl, tm);
		go_Min(v * 2 + 1, tm + 1, tr);
	}
}

void dijkstra(int s) {
	upd_Min(1, 0, n - 1, s, s, 0ll);
	for (int i = 0; i < n; ++i) {
		auto v = get_Min();
		val = v.first;
		if (val == inf) break;
		for (edge f : G[v.second])
			upd_Min(1, 0, n - 1, f.l, f.r, f.w + val);
		go_upd(1, 0, n - 1, v.second);
		not_used(1, 0, n - 1, v.second);
	}
}

int solve() {
	int q, s;
	scanf("%d %d %d", &n, &q, &s);
	--s;
	build_Min(1, 0, n - 1);
	for (int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int v, u, w;
			scanf("%d %d %d", &v, &u, &w);
			G[v - 1].push_back({ u - 1, u - 1, w });
		} else if (t == 2) {
			int v, l, r, w;
			scanf("%d %d %d %d", &v, &l, &r, &w);
			G[v - 1].push_back({ l - 1, r - 1, w });
		} else {
			int v, l, r, w;
			scanf("%d %d %d %d", &v, &l, &r, &w);
			add_edge(1, 0, n - 1, l - 1, r - 1, cnt);
			R[cnt++] = { v - 1, w };
		}
	}

	dijkstra(s);

	go_Min(1, 0, n - 1);
	return 0;
}