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

int N;
int P[300011];
int rnk[300011];

vector<pair<int, int> > ans;
void change(int i, int j) {
    assert(abs(i-j) * 2 >= N);
    ans.emplace_back(i+1, j+1);
    swap(P[i], P[j]);
    rnk[P[i]] = i;
    rnk[P[j]] = j;
}
void go(int i) {
    if (P[i] == i) return;

    while (1) {
	if (abs(i - rnk[i])*2 < N) {
	    if (rnk[i] < N/2) {
		change(rnk[i], N-1);
	    } else {
		change(rnk[i], 0);
	    }
	} else {
	    break;
	}
    }
    change(i, rnk[i]);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i), P[i]--;
#ifdef LOCAL
    N = 10000;
    REP (i, N) P[i] = i;
    random_shuffle(P, P+N);
#endif

    REP (i, N) rnk[P[i]] = i;

    REP (i, N/2) {
	go(N/2+i);
	go(N/2-1-i);
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first, e->second);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}