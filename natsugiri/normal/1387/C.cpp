#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

// ret[i] := #words that is a suffix of t[0:i+1];
const int ALPHA_BASE = 0;
const int ALPHA_SIZE = 2;

struct Node {
    LL sum; 
    int mask, head, fail;
    Node() { 
	sum = 0;
	mask = 0;
	head = 0;
	fail = 0;
    }
    int child(char c) const {
	int t = c-ALPHA_BASE;
	if (~mask>>t&1) return -1;
	return head + __builtin_popcount(mask & ((1<<t)-1));
    }
};

vector<Node> nodes;

int get_next(int x, char c) {
    while (x >= 0 && ~nodes[x].mask>>(c-ALPHA_BASE)&1) x = nodes[x].fail;
    if (x < 0) return 0;
    else return nodes[x].child(c);
}

template<class ITER> void build(ITER begin, ITER end) {
    int n = end - begin;
    VI idx(n);
    REP (i, n) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j){ return begin[i] < begin[j]; });
    nodes.clear();
    nodes.push_back(Node());
    VI depth, left, right;
    depth.push_back(0); left.push_back(0); right.push_back(n);
    for (int i=0; i<(int)nodes.size(); i++) {
	nodes[i].head = nodes.size();
	int j = left[i];
	while (j < right[i] && (int)begin[idx[j]].size() <= depth[i]) {
	    // nodes[i] is end of string begin[idx[j]];
	    // e.g. nodes[i].sum += value[idx[j]]);
	    nodes[i].sum += 1;
	    j++;
	}
	while (j<right[i]) {
	    const char c = begin[idx[j]][depth[i]];
	    int k = j;
	    while (k < right[i] && c == begin[idx[k]][depth[i]]) k++;
	    nodes.push_back(Node());
	    depth.push_back(depth[i]+1); left.push_back(j); right.push_back(k);
	    nodes[i].mask |= 1<<(c-ALPHA_BASE);
	    j = k;
	}
    }

    nodes[0].fail = -1;
    for (int i=1; i<(int)nodes.size(); i++) {
	int k = nodes[i].head;
	for (int j=0; j<ALPHA_SIZE; j++) if (nodes[i].mask>>j&1) {
	    int f = nodes[i].fail;
	    nodes[k].fail = get_next(f, j+ALPHA_BASE);
	    nodes[k].sum += nodes[nodes[k].fail].sum;
	    k++;
	}
    }
}

//VI run(const string &t) {
//    VI v(t.size());
//    int x = 0;
//    REP (i, t.size()) {
//      x = get_next(x, t[i]);
//	v[i] += nodes[x].sum;
//    }
//    return v;
//}

// 3 <= G <= 102;
// 1 <= N <= 100;
// 0 <= M <= 50;

int G, N, M;
struct Mutation {
    int from;
    VI to;

    Mutation() {}

    bool operator<(const Mutation &o) const {
	return from < o.from;
    }
};
vector<Mutation> table;


vector<VI> anti;


__int128 INF;
__int128 dp[111];

namespace SUBTASK1 {
void solve() {
    memset(dp, 0x3f, sizeof dp);
    INF = dp[0];
    dp[0] = dp[1] = 1;

    while (1) {
	bool update = false;
	EACH (e, table) {
	    VI &to = e->to;
	    __int128 sum = 0;
	    EACH (f, to) {
		if (dp[*f] == INF) {
		    sum = INF;
		    break;
		}

		sum += dp[*f];
	    }

	    if (sum < dp[e->from]) {
		update = true;
		dp[e->from] = sum;
	    }
	}

	if (!update) break;
    }
}
}; // SUBTASK1;

namespace SUBTASK2 {

int nxt[55][111]; // [node index][gene] = next node index;
bool dead_edge[55][111];

void solve() {
    build(anti.begin(), anti.end());
    vector<pair<__int128, int> > B;
    for (int i=2; i<G; i++) if (dp[i] != INF) B.emplace_back(dp[i], i);
    sort(B.begin(), B.end());

    memset(nxt, -1, sizeof nxt);
    REP (x, nodes.size()) {
	nxt[x][0] = get_next(x, 0);
	nxt[x][1] = get_next(x, 1);
    }

    REP (t, 2) {
	VI one(1, t);
	if (count(anti.begin(), anti.end(), one)) {
	    dp[t] = INF;

	    REP (x, nodes.size()) {
		dead_edge[x][t] = true;
	    }
	}
    }

    REP (i, B.size()) {
	int g = B[i].second;

	VI &to = table[g-2].to;

	REP (x, nodes.size()) {
	    int cur = x;
	    bool dead = false;
	    REP (j, to.size()) {
		if (dead_edge[cur][to[j]]) dead = true;
		cur = nxt[cur][to[j]];
		if (nodes[cur].sum) dead = true;
	    }

	    if (dead) dead_edge[x][g] = true;
	    nxt[x][g] = cur;
	}

	if (dead_edge[0][g]) {
	    dp[g] = INF;
	}
    }
}

}; // SUBTASK2;

namespace SUBTASK5 {

__int128 cost[55][111][55];
__int128 buf[55][55];
int update_table[111];

void solve() {
    build(anti.begin(), anti.end());
    memset(cost, 0x3f, sizeof cost);

    REP (t, 2) {
	VI one(1, t);
	if (count(anti.begin(), anti.end(), one)) {
	    dp[t] = INF;
	} else {
	    REP (x, nodes.size()) {
		int y = get_next(x, t);
		if (nodes[y].sum == 0) cost[x][t][y] = 1;
	    }
	}
    }

    for (int cnt=1; ; cnt++) {
	bool update = false;

	REP (i, table.size()) {
	    int from = table[i].from;
	    VI &to = table[i].to;

	    bool need_update = false;
	    REP (j, to.size()) if (update_table[to[j]] == cnt - 1) need_update = true;
	    if (!need_update) continue;

	    REP (x, nodes.size()) {
		memset(buf, 0x3f, sizeof buf);
		buf[0][x] = 0;

		REP (j, to.size()) REP (y, nodes.size()) if (buf[j][y] < INF && nodes[y].sum == 0) {
		    REP (z, nodes.size()) {
			__int128 tmp = buf[j][y] + cost[y][to[j]][z];
			amin(buf[j+1][z], tmp);
		    }
		}

		REP (y, nodes.size()) if (cost[x][from][y] > buf[to.size()][y]) {
		    update_table[from] = cnt;
		    update = true;
		    cost[x][from][y] = buf[to.size()][y];
		}
	    }
	}

	if (!update) break;
    }

    static __int128 ans[111];
    REP (g, G) ans[g] = INF;

    for (int g=2; g<G; g++) if (dp[g] != INF) {
	REP (y, nodes.size()) amin(ans[g], cost[0][g][y]);
    }

    REP (g, G) dp[g] = ans[g];

//    vector<pair<__int128, int> > B;
//    for (int i=2; i<G; i++) if (dp[i] != INF) B.emplace_back(dp[i], i);
//    sort(B.begin(), B.end());
//
//    REP (i, B.size()) {
//	int g = B[i].second;
//
//	VI &to = table[g-2].to;
//
//	REP (x, nodes.size()) {
//	    int cur = x;
//	    bool dead = false;
//	    REP (j, to.size()) {
//		if (dead_edge[cur][to[j]]) dead = true;
//		cur = nxt[cur][to[j]];
//		if (nodes[cur].sum) dead = true;
//	    }
//
//	    if (dead) dead_edge[x][g] = true;
//	    nxt[x][g] = cur;
//	}
//
//	if (dead_edge[0][g]) {
//	    dp[g] = INF;
//	}
//    }
}

}; // SUBTASK2;

void MAIN() {
    scanf("%d%d%d", &G, &N, &M);
    table.reserve(N);

    REP (i, N) {
	int a, len;
	scanf("%d%d", &a, &len);
	table.emplace_back();
	table.back().from = a;
	table.back().to.reserve(len);

	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    table.back().to.push_back(x);
	}
    }

    sort(table.begin(), table.end());

    anti.reserve(M);
    REP (i, M) {
	int len;
	scanf("%d", &len);
	anti.emplace_back();
	anti.back().reserve(len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    anti.back().push_back(x);
	}
    }

    SUBTASK1::solve();
    //if (N == G-2) SUBTASK2::solve();
    SUBTASK5::solve();

    for (int i=2; i<G; i++) {
	if (dp[i] == INF) puts("YES");
	else printf("NO %llu\n", (unsigned long long)dp[i]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}