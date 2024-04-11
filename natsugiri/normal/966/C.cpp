#include<random>
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

const int BITS = 60;

int N;
LL A[100011];
LL B[100011];
LL C[100011];

vector<LL> Z[BITS];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", B+i);

#ifdef LOCALX
    {
	mt19937 engine(8);
	N = 7;
	REP (i, N) A[i] = engine() % (1ULL<<60);
	sort(A, A+N);
	LL s = 0;
	REP (i, N) {
	    B[i] = A[i] ^ s;
	    s = A[i];
	}
	rprintf("%llx", A, A+N);
	rprintf("%llx", B, B+N);

	s = 0;
	REP (i, N) {
	    s ^= B[i];
	    A[i] = s;
	}
	rprintf("%llx", A, A+N);
    }
#endif

    REP (i, N) {
	int pos = 0;
	REP (t, BITS) if (B[i]>>t & 1) pos = t;
	Z[pos].push_back(B[i]);
    }

    bool yes = true;
    vector<LL> cur, nxt;
    for (int t=BITS; t--;) {
	if (Z[t].size()) {
	    nxt.clear();
	    int i=0, j=0;
	    int parity = 0;
	    for (; i<(int)Z[t].size(); i++) {
		if (i) {
		    if (j >= (int)cur.size()) {
			yes = false;
			break;
		    }
		    nxt.push_back(cur[j++]);
		    if (nxt.back()>>t & 1) parity ^= 1;
		}

		while (parity == 1 && j < (int)cur.size()) {
		    nxt.push_back(cur[j++]);
		    if (nxt.back()>>t & 1) parity ^= 1;
		}

		if (parity == 1) {
		    yes = false;
		    break;
		}

		nxt.push_back(Z[t][i]);
		parity ^= 1;
	    }

	    if (!yes) break;
	    while (j < (int)cur.size()) nxt.push_back(cur[j++]);
	    swap(cur, nxt);
	}
    }

    if ((int)cur.size() != N) {
	yes = false;
    }

    if (yes) {
	REP (i, N) C[i] = cur[i];
	LL s = 0;
	REP (i, N) {
	    s ^= C[i];
	    A[i] = s;
	}
	REP (i, N-1) if (A[i] >= A[i+1]) yes = false;
    }

    if (yes) {
	puts("Yes");
	//rprintf("%llx", A, A+N);
	rprintf("%lld", C, C+N);
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}