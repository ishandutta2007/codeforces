#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
template<class T> struct PriorityQueue {
    using ULL = unsigned long long;
    static const int SIZE = 65;
    unsigned sz;
    ULL last;
    vector<pair<ULL, T> > b[SIZE];

    static ULL bsr(ULL x) {
	return x? 64u - __builtin_clzll(x): 0u;
    }

    PriorityQueue() {
	sz = last = 0;
    }

    bool empty() const { return sz == 0; }

    unsigned size() const { return sz; }

    void push(ULL x, const T &v) {
	assert(last <= x);
	sz++;
	b[bsr(x^last)].emplace_back(x, v);
    }

    pair<ULL, T> get_min() {
	assert(sz);
	if (b[0].empty()) {
	    int k = 1;
	    while (b[k].empty()) k++;
	    last = b[k][0].first;
	    EACH (e, b[k]) amin(last, e->first);
	    REP (i, b[k].size()) b[bsr(b[k][i].first^last)].push_back(b[k][i]);
	    b[k].clear();
	}
	return b[0].back();
    }

    void pop_min() {
	if (b[0].empty()) get_min();
	b[0].pop_back();
	sz--;
    }
};

int N, M;
vector<pair<int, int> > O[100011];
// N + 51 * N;
//   100000
//  5100000
const int SIZE = 5500011;
LL dp[SIZE];


int id(int x, int w) {
    return N + 51 * x + w;
}

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;

	O[x].emplace_back(y, w);
	O[y].emplace_back(x, w);
    }


    memset(dp, 0x3f, sizeof dp);
    const LL INF = dp[0];

    PriorityQueue<int> Q;
    Q.push(0, 0);
    dp[0] = 0;
    while (!Q.empty()) {
	pair<unsigned long long, int> p = Q.get_min();
	Q.pop_min();
	int v = p.second;
	LL cst = p.first;
	if (dp[v] != cst) continue;

	if (v < N) {
	    EACH (e, O[v]) {
		int y = e->first;
		int w = e->second;

		int z = id(y, w);
		if (dp[z] > cst) {
		    dp[z] = cst;
		    Q.push(cst, z);
		}
	    }
	} else {
	    int a = (v - N) % 51;
	    int x = (v - N) / 51;
	    eprintf("%d %d\n", a, x);

	    EACH (e, O[x]) {
		int y = e->first;
		int b = e->second;

		LL nxt = cst + (a+b)*(a+b);
		if (dp[y] > nxt) {
		    dp[y] = nxt;
		    Q.push(nxt, y);
		}
	    }
	}
    }

    REP (i, N) {
	LL ans;
	if (dp[i] == INF) {
	    ans = -1;
	} else {
	    ans = dp[i];
	}
	printf("%lld%c", ans, " \n"[i==N-1]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}