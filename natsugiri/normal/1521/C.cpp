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
int A[100011] = {3, 2, 1};


bool use[100011];
int ans[100011];

int Q1(int x, int i, int j) {
    printf("? 1 %d %d %d\n", i+1, j+1, x);
    fflush(stdout);

#ifdef LOCAL
    int q = max(min(x, A[i]), min(x+1, A[j]));
    printf("ret = %d\n", q);
    return q;
#endif

    int ret;
    scanf("%d", &ret);
    return ret;
}

int Q2(int x, int i, int j) {
    printf("? 2 %d %d %d\n", i+1, j+1, x);
    fflush(stdout);

#ifdef LOCAL
    int q = min(max(x, A[i]), max(x+1, A[j]));
    printf("ret = %d\n", q);
    return q;
#endif

    int ret;
    scanf("%d", &ret);
    return ret;
}

void ANS() {
    printf("! ");
    rprintf("%d", ans, ans+N);
    fflush(stdout);
}

void MAIN() {
    scanf("%d", &N);

    for (int i=0; i+1<N; i+=2) {
	int a = Q2(1, i, i+1);

	if (a == 1) {
	    ans[i] = 1;
	    ans[i+1] = -1;
	} else if (a == 2) {
	    int a2 = Q2(1, i+1, i);
	    if (a2 == 1) {
		ans[i] = -1;
		ans[i+1] = 1;
	    } else {
		int b = Q2(2, i, i+1);
		if (b == 2) {
		    ans[i] = 2;
		    ans[i+1] = -1;
		} else {
		    assert(b == 3);
		    ans[i] = -1;
		    ans[i+1] = 2;
		}
	    }
	} else {
	    int b = Q2(a, i, i+1);
	    if (a == b) {
		ans[i] = a;
		ans[i+1] = -1;
	    } else {
		assert(b == a+1);
		ans[i] = -1;
		ans[i+1] = a;
	    }
	}


	if (ans[i+1] == -1) {
	    int s = Q1(N-1, i, i+1);
	    ans[i+1] = s;
	} else {
	    int s = Q1(N-1, i+1, i);
	    ans[i] = s;
	}
    }

    if (N % 2) {
	for (int i=1; i<=N; i++) use[i] = false;
	REP (i, N-1) use[ans[i]] = true;
	for (int i=1; i<=N; i++) if (!use[i]) ans[N-1] = i;
    }

    ANS();
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}