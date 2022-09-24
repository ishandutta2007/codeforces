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

// 2 3 4 5
// s[r] <= t
// sum s[l..r] <= t * m;
LL A, B;
int N;

const int MAX = 1000111;
LL S[MAX+11], sums[MAX+11];

int main() {
    scanf("%lld%lld%d", &A, &B, &N);
    S[1] = A;
    for (int i=1; i<MAX-1; i++) {
	S[i+1] = min(S[i] + B, (LL)MAX);
    }

    REP (i, MAX) sums[i+1] = sums[i] + S[i];

    REP ($, N) {
	int L;
	LL T, M;
	scanf("%d%lld%lld", &L, &T, &M);
	int lo = L-1, hi = MAX;
	while (hi - lo > 1) {
	    int mid = (hi + lo) / 2;
	    if (S[mid] <= T && sums[mid+1] - sums[L] <= T * min(M, (LL)mid - L + 1)) {
		lo = mid;
	    } else {
		hi = mid;
	    }
	}

	if (lo == L-1) puts("-1");
	else printf("%d\n", lo);
    }


    return 0;
}