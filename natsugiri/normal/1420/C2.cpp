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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
template<class T> void make_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N, Q;
int A[300011];

bool top(int i) {
    return (i == 0 || A[i-1] < A[i]) && (i == N-1 || A[i] > A[i+1]);
}
bool bottom(int i) {
    return i != 0 && i != N-1 && A[i-1] > A[i] && A[i] < A[i+1];
}

VI idx;

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    LL sum = 0;
    REP (i, N) {
	if (top(i)) sum += A[i];
	else if (bottom(i)) sum -= A[i];
    }

    printf("%lld\n", sum);
    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--; r--;

	if (l != r) {
	    idx.clear();
	    for (int i=-1; i<=1; i++) {
		if (0 <= l+i && l+i < N) idx.push_back(l+i);
		if (0 <= r+i && r+i < N) idx.push_back(r+i);
	    }
	    make_unique(idx);
	    EACH (e, idx) {
		if (top(*e)) sum -= A[*e];
		else if (bottom(*e)) sum += A[*e];
	    }

	    swap(A[l], A[r]);

	    EACH (e, idx) {
		if (top(*e)) sum += A[*e];
		else if (bottom(*e)) sum -= A[*e];
	    }
	}

	printf("%lld\n", sum);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}