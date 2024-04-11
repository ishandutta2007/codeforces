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


int L, R;
int N;
int A[1<<17];
int B[1<<17];

bool check(int X) {
    REP (i, N) B[i] = A[i] ^ X;
    sort(B, B+N);
    if (B[0] != L) return false;
    if (B[N-1] != R) return false;
    REP (i, N-1) if (B[i]+1 != B[i+1]) return false;
    return true;
}

void MAIN() {
    scanf("%d%d", &L, &R);
    N = R - L + 1;
    REP (i, N) scanf("%d", A+i);


#ifdef LOCALx
    L = rand() % (1<<17);
    R = rand() % (1<<17);
    if (L > R) swap(L, R);
    N = R - L + 1;
    int ans = rand() % (1<<17);
    REP (i, N) A[i] = (L + i) ^ ans;
    printf("ans = %d %x, (%d %d)\n", ans, ans, L, R);
#endif


    sort(A, A+N);

    int X = 0;
    for (int t=17; t>=0; t--) {
	int c[2] = {};
	REP (i, N) c[(L+i)>>t&1]++;

	if (c[0] == N) {
	    if (A[0]>>t&1) {
		X ^= 1<<t;
	    }
	} else if (c[1] == N) {
	    if (~A[0]>>t&1) {
		X ^= 1<<t;
	    }
	} else {
	    REP ($, 2) {
		bool yes = true;

		for (int s=t-1; s>=0; s--) {
		    int d[2][2] = {};
		    REP (i, N) {
			int a = A[i];
			if (X>>t&1) a ^= 1<<t;
			d[a>>t&1][a>>s&1]++;
		    }

		    bool need_flip = false;
		    bool never_flip = false;
		    if (d[1][0] < d[1][1]) need_flip = true;
		    if (d[1][0] > d[1][1]) never_flip = true;
		    if (d[0][0] > d[0][1]) need_flip = true;
		    if (d[0][0] < d[0][1]) never_flip = true;

		    if (need_flip && never_flip) {
			yes = false;
			break;
		    } else if (need_flip) {
			X ^= 1<<s;
		    }
		}

		if (yes && check(X)) {
		    printf("%d\n", X);
		    return;
		}
		// eprintf("yes = %d, X = %d, %x\n", yes, X, X);

		X ^= 1<<t;
		X &= ~((1<<t)-1);
	    }

	    assert(false);
	}
    }

    printf("%d\n", X);
    assert(check(X));
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}