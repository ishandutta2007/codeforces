#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int query(const VI &v) {
    printf("? %d ", (int)v.size());
    rprintf("%d", v.begin(), v.end());
    fflush(stdout);

    static char S[11];
    scanf("%s", S);
    return *S == 'Y';

}

bool answer(int a) {
    printf("! %d\n", a);
    fflush(stdout);
    static char S[11];
    scanf("%s", S);
    return S[1] == ')';
}

VI X, A, B, nxt;

void MAIN() {
    scanf("%d", &N);

    if (N == 1) {
	answer(1);
	return;
    }

    X.clear();
    REP (i, N) X.push_back(i+1);

    while (X.size() >= 4u) {
	A.clear();
	B.clear();
	REP (i, X.size()) {
	    if (i % 4 == 0 || i % 4 == 1) {
		A.push_back(X[i]);
	    }
	    if (i % 4 == 0 || i % 4 == 2) {
		B.push_back(X[i]);
	    }
	}

	bool qa = query(A);
	bool qb = query(B);

	int mask = 0;

	if (qa) mask |= 1 | 2;
	else mask |= 4 | 8;

	if (qb) mask |= 1 | 4;
	else mask |= 2 | 8;

	nxt.clear();
	REP (i, X.size()) {
	    if (mask >> (i % 4) & 1) {
		nxt.push_back(X[i]);
	    }
	}
	swap(X, nxt);
    }


    if (X.size() == 3u) {
	int a = X[0];
	int b = X[1];
	int c = X[2];
	X.clear();

	A.clear();
	A.push_back(a);
	A.push_back(b);

	if (query(A) && query(A)) {
	    X = A;
	} else {
	    B.clear();
	    B.push_back(a);
	    B.push_back(c);

	    if (query(B)) {
		// a c;
		X = B;
	    } else {
		// b c;
		X.push_back(b);
		X.push_back(c);
	    }
	}
    }

    int a = X[0];
    int b = X[1];

    bool res = answer(a) || answer(b);
    assert(res);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}