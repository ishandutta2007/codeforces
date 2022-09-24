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

int N;
int A[300011];
pair<int, int> P[300011];
VI idx;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);

    int ans = 0;
    LL inv = 0;

    for (int t=30; t--;) {
	int t1 = t+1;
	LL one_zero = 0;
	LL zero_one = 0;
	for (int i=0; i<N;) {
	    int j = i;
	    while (j < N && (P[i].first>>t1) == (P[j].first>>t1)) j++;

	    idx.clear();
	    for (int x=i; x<j; x++) if (~P[x].first>>t&1) {
		idx.push_back(P[x].second);
	    }
	    sort(idx.begin(), idx.end());
	    for (int x=i; x<j; x++) if (P[x].first>>t&1) {
		int pos = lower_bound(idx.begin(), idx.end(), P[x].second) - idx.begin();
		zero_one += pos;
		one_zero += (int)idx.size() - pos;
	    }

	    i = j;
	}

//	eprintf("%lld %lld\n", zero_one, one_zero);

	if (one_zero > zero_one) {
	    ans |= 1<<t;
	    inv += zero_one;
	} else {
	    inv += one_zero;
	}
    }


    printf("%lld %d\n", inv, ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}