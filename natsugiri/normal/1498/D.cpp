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

int N;
int M;

int Z[100011];
int C[100011];



void MAIN() {
    scanf("%d%d", &N, &M);

    memset(Z, 0x3f, sizeof Z);
    const int INF = Z[0];
    Z[0] = 0;

    for (int time=1; time<=N; time++) {
	int t;
	LL x, y;
	scanf("%d%lld%lld", &t, &x, &y);
	if (t == 1) {
	    x = (x + 99999) / 100000;
	    REP (i, M) {
		if (Z[i] == INF) continue;
		if (i + x > M) break;

		if (Z[i+x] <= time) continue;


		if (Z[i] < time) {
		    Z[i+x] = time;
		    C[i+x] = 1;
		} else if (C[i] < y) {
		    Z[i+x] = time;
		    C[i+x] = C[i] + 1;
		}
	    }

	} else {
	    REP (i, M) {
		if (Z[i] == INF) continue;

		LL j = (i * x + 99999) / 100000;

		if (j > M) break;

		if (Z[j] < time) continue;

		if (Z[i] < time) {
		    Z[j] = time;
		    C[j] = 1;
		} else if (C[i] < y) {
		    if (Z[j] == time) amin(C[j], C[i]+1);
		    else {
			Z[j] = time;
			C[j] = C[i] + 1;
		    }
		}
	    }
	}
    }

    REP (i, M+1) if (Z[i] == INF) Z[i] = -1;
    rprintf("%d", Z+1, Z+M+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}