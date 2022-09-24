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
VI G[100111];
VI D[2];
int dep[100111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int x;
	scanf("%d", &x);
	x--;
	G[x].push_back(i+1);
    }

    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	D[dep[v] & 1].push_back(A[v]);

	EACH (e, G[v]) {
	    dep[*e] = dep[v] + 1;
	    ord.push_back(*e);
	}
    }

    REP (t, 2)
	sort(D[t].begin(), D[t].end());


    int depth = *max_element(dep, dep + N);
    int L = depth & 1, R = 1 - L;
    int game = 0;
    LL ans = 0;
    EACH (e, D[L]) game ^= *e;

    EACH (e, D[L]) {
	int g = game ^ *e;
	int cnt = upper_bound(D[R].begin(), D[R].end(), g) 
	    - lower_bound(D[R].begin(), D[R].end(), g);
	ans += cnt;
    }
    if (game == 0) {
	REP (t, 2) {
	    ans += (LL)D[t].size() * (D[t].size()-1) / 2;
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