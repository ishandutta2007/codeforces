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

int ans[1<<16];
int N;

int cnt;
void test() {
#ifdef MYTEST
    N = 4;
    REP (i, N) ans[i] = i;
    random_shuffle(ans, ans+N);
    random_shuffle(ans, ans+N);
    random_shuffle(ans, ans+N);
#endif
}

int A[1<<16];

int XOR(int x, int y) {
    cnt++;
    printf("XOR %d %d\n", x+1, y+1);
    fflush(stdout);

#ifdef MYTEST
    return ans[x] ^ ans[y];
#endif

    int z;
    scanf("%d", &z);
    return z;
}
int AND(int x, int y) {
    cnt++;
    printf("AND %d %d\n", x+1, y+1);
    fflush(stdout);

#ifdef MYTEST
    return ans[x] & ans[y];
#endif

    int z;
    scanf("%d", &z);
    return z;
}

void MAIN() {
    scanf("%d", &N);
    test();

    for (int i=1; i<N; i++) {
	int x = XOR(0, i);
	A[i] = x;
    }

    int AND01 = AND(0, 1);
    int AND02 = AND(0, 2);
    int AND12 = AND(1, 2);

    REP (t, 16) {
	if (A[1]>>t & 1) {
	    if (A[2]>>t & 1) {
		// 011 vs 100
		if (AND12>>t & 1) {
		    ;
		} else {
		    A[0] += 1<<t;
		}
	    } else {
		// 010 vs 101;
		if (AND02>>t & 1) {
		    A[0] += 1<<t;
		}
	    }
	} else {
	    if (AND01>>t & 1) {
		A[0] |= 1<<t;
	    }
	}
    }

    for (int i=1; i<N; i++) {
	A[i] ^= A[0];
    }


    printf("! ");
    rprintf("%d", A, A+N);
    fflush(stdout);

#ifdef MYTEST
    printf("! ");
    rprintf("%d", ans, ans+N);
    REP (i, N) assert(ans[i] == A[i]);
    assert(cnt <= N+1);
#endif
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}