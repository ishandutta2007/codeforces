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
int A[111][111];

void query(int b, int i, int j) {
    printf("%d %d %d\n", b, i+1, j+1);
    fflush(stdout);
    A[i][j] = b;
}

void MAIN() {
    scanf("%d", &N);
    vector<pair<int, int> > one, two;
    REP (i, N) REP (j, N) {
	if ((i+j) % 2 == 0) two.emplace_back(i, j);
	else one.emplace_back(i, j);
    }

    REP (t, N*N) {
	int a;
	scanf("%d", &a);

	if (a != 2 && two.size()) {
	    query(2, two.back().first, two.back().second);
	    two.pop_back();
	} else if (a != 1 && one.size()) {
	    query(1, one.back().first, one.back().second);
	    one.pop_back();
	} else {
	    if (two.size()) {
		query(3, two.back().first, two.back().second);
		two.pop_back();
	    } else {
		query(3, one.back().first, one.back().second);
		one.pop_back();
	    }
	}
    }

#ifdef LOCAL
    REP (i, N) rprintf("%d", A[i], A[i]+N);
#endif
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}