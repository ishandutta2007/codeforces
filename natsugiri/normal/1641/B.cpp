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
int A[1011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    bool yes = true;
    if (N % 2 == 1) yes = false;
    vector<pair<int, int> > op;
    VI len;

    if (yes) {
	while (N) {
	    if (A[N-1] == A[N-2]) {
		len.push_back(2);
		N -= 2;
	    } else {
		int pivot = -1;
		for (int i=N-2; i>=0; i--) if (A[i] == A[N-1]) {
		    pivot = i;
		    break;
		}
		if (pivot == -1) {
		    yes = false;
		    break;
		}

		int pos = pivot+1;
		for (int k=N-1; k>pivot; k--) {
		    op.emplace_back(pos, A[k]);
		    pos++;
		}
		len.push_back((N-pivot-1)*2);
		reverse(A+pivot+1, A+N);
		pos = pivot;
		for (int k=N-1; k>pivot; k--) {
		    op.emplace_back(pos, A[k]);
		    pos++;
		}

		len.push_back((N-pivot)*2);
		reverse(A+pivot, A+N);
		N -= 2;
	    }
	}
    }

    if (yes) {
	printf("%d\n", (int)op.size());
	EACH (e, op) printf("%d %d\n", e->first, e->second);
	printf("%d\n", (int)len.size());
	reverse(len.begin(), len.end());
	rprintf("%d", len.begin(), len.end());
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}