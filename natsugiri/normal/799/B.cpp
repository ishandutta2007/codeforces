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

int N, M;
vector<pair<int, int> > Z[3];
int P[200111], A[200111], B[200111];
int ans[200111];
bool use[200111];

void MAIN() {
    scanf("%d", &N);

    REP (i, N) scanf("%d", P+i);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, N) scanf("%d", B+i), B[i]--;

    REP (i, N) {
	Z[A[i]].emplace_back(P[i], i);
	Z[B[i]].emplace_back(P[i], i);
    }
    REP (i, 3) sort(Z[i].rbegin(), Z[i].rend());

    scanf("%d", &M);
    REP (i, M) {
	int c;
	scanf("%d", &c);
	c--;
	while (!Z[c].empty() && use[Z[c].back().second])
	    Z[c].pop_back();

	if (Z[c].empty()) {
	    ans[i] = -1;
	} else {
	    ans[i] = P[Z[c].back().second];
	    use[Z[c].back().second] = true;
	}
    }

    rprintf("%d", ans, ans + M);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}