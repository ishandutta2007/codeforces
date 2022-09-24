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

int N, M, K;
int A[200011], B[200011];
vector<pair<int, int> > G[200011];
bool ban[200011];
int deg[200011];

int ptr = 0;
VI ord;
int ans[200011];

void go(int has) {
    for (; ptr < (int)ord.size(); ptr++) {
	int v = ord[ptr];
	EACH (e, G[v]) {
	    int w = e->first;
	    int id = e->second;
	    if (id <= has && !ban[w]) {
		deg[w]--;
		if (deg[w] < K) {
		    ban[w] = true;
		    ord.push_back(w);
		}
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
	G[A[i]].emplace_back(B[i], i);
	G[B[i]].emplace_back(A[i], i);
    }

    REP (i, N) deg[i] = G[i].size();
    ord.reserve(N);

    REP (i, N) if (deg[i] < K) {
	ban[i] = true;
	ord.push_back(i);
    }

    for (int i=M-1; i>=0; i--) {
	go(i);
	ans[i] = N - ord.size();

	if (!ban[A[i]] && !ban[B[i]]) {
	    deg[A[i]]--;
	    if (deg[A[i]] < K) {
		ord.push_back(A[i]);
		ban[A[i]] = true;
	    }
	    deg[B[i]]--;
	    if (deg[B[i]] < K) {
		ord.push_back(B[i]);
		ban[B[i]] = true;
	    }
	}
    }

    REP (i, M) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}