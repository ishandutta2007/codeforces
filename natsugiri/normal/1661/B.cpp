#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

const int MOD = 1<<15;
int cost[MOD];

void init() {
    memset(cost, 0x3f, sizeof cost);
    cost[0] = 0;
    VI q0, q1;
    q0.push_back(0);
    while (!q0.empty()) {
	while (!q0.empty()) {
	    int v = q0.back();
	    q0.pop_back();
	    int w = (v - 1 + MOD) % MOD;
	    if (cost[w] > cost[v] + 1) {
		cost[w] = cost[v] + 1;
		q1.push_back(w);
	    }

	    if (v % 2 == 0) {
		w = v / 2 % MOD;
		if (cost[w] > cost[v] + 1) {
		    cost[w] = cost[v] + 1;
		    q1.push_back(w);
		}

		w |= 1<<14;
		if (cost[w] > cost[v] + 1) {
		    cost[w] = cost[v] + 1;
		    q1.push_back(w);
		}
	    }
	}

	swap(q0, q1);
    }
}

int N;

void MAIN() {
    init();
    scanf("%d", &N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	printf("%d%c", cost[a], " \n"[i==N-1]);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}