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

int N, K;
int A[100111];
int factor[62];
int has[62];
int inner[62];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    int stop = 0;
    {
	int m = K;
	for (int i=2; i*i<=m; i++) {
	    int cnt = 0;
	    while (m % i == 0) {
		m /= i;
		cnt++;
	    }
	    if (cnt) {
		factor[stop] = i;
		has[stop] = cnt;
		stop++;
	    }
	}

	if (m > 1) {
	    factor[stop] = m;
	    has[stop] = 1;
	    stop++;
	}
    }

    LL ans = 0;
    int good = 0;
    for (int x=0, y=0; x<N; x++) {
	while (y <= x || (y < N && good < stop)) {
	    int m = A[y];
	    REP (i, stop) {
		while (m % factor[i] == 0) {
		    m /= factor[i];
		    inner[i]++;
		    if (inner[i] == has[i]) good++;
		}
	    }

	    y++;
	}

	if (good == stop) {
	    ans += N - y + 1;
	}

	{
	    int m = A[x];
	    REP (i, stop) {
		while (m % factor[i] == 0) {
		    m /= factor[i];
		    if (inner[i] == has[i]) good--;
		    inner[i]--;
		}
	    }
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}