#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int M;
LL D[200011][4];

struct State {
    int v;
    int s;
    LL cst;

    State() {}
    State(int v_, int s_, LL cst_): v(v_), s(s_), cst(cst_) {}

    bool operator<(const State &o) const {
	return cst > o.cst;
    }
};

vector<pair<int, int> > G[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	G[x].emplace_back(y, c);
	G[y].emplace_back(x, c);
    }

    memset(D, 0x3f, sizeof D);
    D[0][0] = 0;

    priority_queue<State> Q;
    Q.emplace(0, 0, 0);
    while (!Q.empty()) {
	State s = Q.top();
	Q.pop();

	if (D[s.v][s.s] != s.cst) continue;
	EACH (e, G[s.v]) {
	    int w = e->first;
	    LL c = e->second;

	    REP (a, 4) {
		if (a & s.s) continue;
		LL tmp = s.cst + c;
		if (a & 1) tmp -= c;
		if (a & 2) tmp += c;
		int ns = s.s | a;

		if (D[w][ns] > tmp) {
		    D[w][ns] = tmp;
		    Q.emplace(w, ns, tmp);
		}
	    }
	}
    }

    for (int i=1; i<N; i++) printf("%lld%c", D[i][3], " \n"[i==N-1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}