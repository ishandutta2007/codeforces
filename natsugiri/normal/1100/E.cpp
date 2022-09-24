#include<stack>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
struct Edge {
    int to, cost, i;
};
vector<Edge> G[100011];
int deg[100011];
int depth[100011];

bool ok(int mid) {
    memset(deg, 0, sizeof deg);
    REP (v, N) EACH (e, G[v]) if (e->cost > mid) {
	deg[e->to]++;
    }
    stack<int> st;
    REP (v, N) if (deg[v] == 0) st.push(v);

    int cnt = 0;
    while (!st.empty()) {
	int v = st.top(); st.pop();
	depth[v] = cnt++;
	EACH (e, G[v]) if (e->cost > mid) {
	    deg[e->to]--;
	    if (deg[e->to] == 0) st.push(e->to);
	}
    }
    return cnt == N;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	G[x].push_back((Edge){ y, c, i});
    }

    int lo = -1, hi = 1000000000;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    ok(hi);
    VI ans;
    REP (v, N) EACH (e, G[v]) if (e->cost <= hi && depth[v] > depth[e->to]) {
	ans.push_back(e->i+1);
    }
    printf("%d %d\n", hi, (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}