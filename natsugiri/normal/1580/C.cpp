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

int N, M;
LL X[200011], Y[200011];
int T[200011];

int ans[200011];
int sums[200011];
const int MAGIC = 400;
int B[MAGIC][MAGIC];
int iter[MAGIC];


void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);

    REP (t, M) {
	int op, k;
	scanf("%d%d", &op, &k);
	k--;
	LL step = X[k] + Y[k];
	if (op == 1) {
	    T[k] = t;
	    if (step < MAGIC) {
		LL v = (t+X[k]) % step;
		REP (y, Y[k]) {
		    B[step][v]++;
		    v++;
		    if (v == step) v = 0;
		}
	    } else {
		for (LL i=t; i<M; i+=step) {
		    sums[min((LL)M, i+X[k])]++;
		    sums[min((LL)M, i+step)]--;
		}
	    }
	} else {
	    if (step < MAGIC) {
		LL v = (T[k]+X[k]) % step;
		REP (y, Y[k]) {
		    B[step][v]--;
		    v++;
		    if (v == step) v = 0;
		}
	    } else {
		for (LL i=T[k]; i<M; i+=step) {
		    if (t < min((LL)M, i+step)) {
			sums[min((LL)M, i+X[k])]--;
			sums[min((LL)M, i+step)]++;
			if (i+X[k] < t) {
			    sums[i+X[k]]++;
			    sums[min((LL)t, i+step)]--;
			}
		    }
		}
	    }
	}

	for (int a=1; a<MAGIC; a++) {
	    ans[t] += B[a][iter[a]];
	    iter[a]++;
	    if (iter[a] == a) iter[a] = 0;
	}
    }

    REP (t, M) {
	sums[t+1] += sums[t];
	ans[t] += sums[t];
	printf("%d\n", ans[t]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}