#include<deque>
#include<stack>
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}


int N, K;
bool ban[1024];

int A[1024];
int qcnt;
deque<int> dq;
// contains?
bool query(int c) {
    qcnt++;
    printf("? %d\n", c+1);
#ifdef MYTEST 
    rprintf("%d,", dq.begin(), dq.end());
    bool ret = false;
    EACH (e, dq) if (*e == A[c]) ret = true;
    dq.push_back(A[c]);
    if ((int)dq.size() > K) dq.pop_front();
    puts(ret? "Y": "N");
    return ret;
#else
    fflush(stdout);
    char s[11];
    scanf("%s", s);
    return *s == 'Y';
#endif
}

void reset() {
    dq.clear();
    puts("R");
    fflush(stdout);
}

void MAIN() {
    scanf("%d%d", &N, &K);
    int M = N/K;

#ifdef MYTEST
    REP (i, N) A[i] = i%3;
#endif

    if (N == K) {
	REP (i, N) {
	    int t = query(i);
	    if (t) ban[i] = true;
	}
    } else {
	for (int sh=1; sh<M; sh++) {
	    REP (s, sh) {
		if (s + sh >= M) break;
		for (int i=s; i<M; i+=sh) {
		    int left = i*K, right = left + K;
		    for (int j=left; j<right; j++) if (!ban[j]) {
			int t = query(j);
			if (t) ban[j] = true;
		    }
		}
		reset();

		for (int i=s; i<M; i+=sh) {
		    int left = i*K, right = left + K;
		    for (int j=right-1; j>=left; j--) if (!ban[j]) {
			int t = query(j);
			if (t) ban[j] = true;
		    }
		}
		reset();
	    }
	}
    }

    int cnt = 0;
    REP (i, N) if (!ban[i]) cnt++;
    printf("! %d\n", cnt);
    fflush(stdout);

    eprintf("%d %d\n", N*N*3/2/K, qcnt);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}