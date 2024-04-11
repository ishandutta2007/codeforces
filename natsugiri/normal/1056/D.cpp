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
VI G[100011];
int C[100011];
int ans[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	G[p].push_back(i+1);
    }

    if (N == 1) {
	puts("1");
	return;
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	if (G[v].empty()) {
	    C[v] = 1;
	} else {
	    C[v] = 0;
	    EACH (e, G[v]) C[v] += C[*e];
	}
    }

//    rprintf("%d", C, C+N);
    sort(C, C+N);
    int len = 0;
    for (int i=1; i<=N; i++) {
	while (len < N && C[len] <= i) {
	    len++;
	    ans[len] = i;
	}
    }
    rprintf("%d", ans+1, ans+N+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}