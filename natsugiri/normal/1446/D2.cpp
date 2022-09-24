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

#ifdef LOCAL
const int MAGIC = 450;
#else
const int MAGIC = 450;
#endif

int N;
int A[200011];
int C[200011];

bool is_unique() {
    REP (i, N) if (A[i] != A[0]) return false;
    return true;
}

int X;
int know[200011];

VI B[200011];

int sums[200011];
int LX[200011];
int RX[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

#ifdef MYTEST
    N = 200000;
    REP (i, N) {
	if (i < 300 || N-300 <= i) {
	    A[i] = 10;
	} else {
	    A[i] = rand() % 100000;
	}
    }

#endif

    int ma = *max_element(A, A+N);


    if (is_unique()) {
	puts("0");
	return;
    }

    REP (i, N) {
	C[A[i]]++;
    }

    X = max_element(C, C+N+1) - C;

    REP (i, N) {
	sums[i+1] = sums[i];
	if (A[i] == X) sums[i+1]++;
    }

    {
	int pos = -1;
	REP (i, N) {
	    LX[i] = pos;
	    if (A[i] == X) pos = i;
	}
	LX[N] = pos;

	pos = N;
	RX[N] = N;
	for (int i=N; i--;) {
	    RX[i] = pos;
	    if (A[i] == X) pos = i;
	}
    }

    REP (i, N) {
	B[A[i]].push_back(i);
    }

    int ans = 0;

    REP (t, ma + 1) {
	if (t == X) continue;

	if (C[t] <= MAGIC) {
	    for (int i=0; i<(int)B[t].size(); i++) {
		for (int j=i; j<(int)B[t].size(); j++) {
		    int l = B[t][i];
		    int r = B[t][j];
		    int ts = j-i+1;
		    int xs = sums[r] - sums[l];
		    if (xs > ts) continue;

		    l = LX[l];
		    r = RX[r];

		    int L = (i == 0? -1: B[t][i-1]);
		    int R = (j+1 == (int)B[t].size()? N: B[t][j+1]);

		    while (l > L && sums[r] - sums[l+1] < ts) l = LX[l];
		    while (r < R && sums[r] - sums[l+1] < ts) r = RX[r];
		    assert(sums[r] - sums[l+1] <= ts);
		    amax(ans, r-l-1);

//		    eprintf("%d (%d %d) %d %d, %d %d\n", t, B[t][i], B[t][j], l, r, L, R);

		    while (l < B[t][i] && r < R) {
			if (l == -1) {
			    if (A[0] == X) l = 0;
			    else l = RX[0];
			} else {
			    l = RX[l];
			}
			r = RX[r];

//			eprintf("%d (%d %d) %d %d, %d %d\n", t, B[t][i], B[t][j], l, r, L, R);
			if (l < B[t][i]) {
			    assert(sums[r] - sums[l+1] <= ts);
			    amax(ans, r-l-1);
			}
		    }
		}
	    }
	} else {
	    memset(know, -1, sizeof know);
	    int sum = 0;
	    know[0] = 0;

	    REP (i, N) {
		if (A[i] == t) {
		    sum--;
		} else if (A[i] == X) {
		    sum++;
		}

		if (sum <= 0) {
		    amax(ans, i+1);
		} else if (know[sum] != -1) {
		    amax(ans, i+1 - know[sum]);
		} else {
		    know[sum] = i+1;
		}
	    }
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}