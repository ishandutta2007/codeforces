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

int N;
const int LIMIT = 130;
LL dp[1<<16][LIMIT]; 

char C[17];
int R[17], B[17];
int red_cards[1 << 16], blue_cards[1 << 16];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%s%d%d", C+i, R+i, B+i);

//    if (0) {
//	N = 16;
//	REP (i, N) {
//	    C[i] = rand() & 1 ? 'R': 'B';
//	    R[i] = rand() % 10000000;
//	    B[i] = rand() % 10000000;
//	}
//    }

    REP (S, 1 << N) {
	REP (i, N) if (S & (1 << i)) {
	    if (C[i] == 'R') red_cards[S]++;
	    else blue_cards[S]++;
	}
    }

    memset(dp, 0xc0, sizeof dp);
    dp[0][0] = 0;

    REP (S, 1 << N) {
	REP (r, LIMIT) if (dp[S][r] >= 0) {
	    REP (i, N) if (~S & (1<<i)) {
		int nS = S | (1 << i);
		int dr = min(red_cards[S], R[i]);
		int db = min(blue_cards[S], B[i]);
		if (r + dr < LIMIT) {
		    amax(dp[nS][r + dr], dp[S][r] + db);
		}
	    }
	}
    }

    LL r_sum = 0, b_sum = 0;
    REP (i, N) {
	r_sum += R[i];
	b_sum += B[i];
    }
    LL ans = 1LL<<60;
    REP (r, LIMIT) {
	LL tmp = max(r_sum - r, b_sum - dp[(1<<N)-1][r]);
	amax(tmp, 0LL);
	amin(ans, tmp + N);
    }

    printf("%lld\n", ans);

    return 0;
}