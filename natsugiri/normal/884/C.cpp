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
int A[100111];
bool use[100111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    VI ls;
    REP (i, N) if (!use[i]) {
	int j = i;
	int len = 0;
	do {
	    len++;
	    use[j] = true;
	    j = A[j];
	} while (j != i);
	ls.push_back(len);
    }

    if (ls.size() > 1u) {
	sort(ls.begin(), ls.end());
	int k = ls.back();
	ls.pop_back();
	ls.back() += k;
    }
    LL ans = 0;
    EACH (e, ls) ans += (LL) *e * *e;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}