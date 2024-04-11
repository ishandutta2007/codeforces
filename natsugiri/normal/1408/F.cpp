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
int A[15011];
void test(vector<pair<int, int> > &ans) {
    assert((int)ans.size() <= 500000);
    REP (i, N) A[i] = i;
    EACH (e, ans) {
	int x, y;
	x = e->first;
	y = e->second;
	int tmp = A[x] + A[y] * 31;
	A[x] = A[y] = tmp;
    }
//    rprintf("%d", A, A+N);

    sort(A, A+N);
    REP (i, N) assert(A[i] == A[0] || A[i] == A[N-1]);
}

void MAIN() {
    scanf("%d", &N);
    int limit = 1;
    while (limit * 2 <= N) limit *= 2;
    int shift = 1;
    vector<pair<int, int> > X;

    while (shift * 2 <= limit) {
	for (int left=0; left<limit; left+=shift*2) {
	    REP (i, shift) {
		if (left + i + shift < limit) {
		    X.emplace_back(left + i, left + i + shift);
		}
	    }
	}
	shift *= 2;
    }

    vector<pair<int, int> > ans = X;
    REP (i, X.size()) {
	ans.emplace_back(N-1-X[i].first, N-1-X[i].second);
    }
    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	printf("%d %d\n", e->first+1, e->second+1);
    }

#ifdef LOCAL
    test(ans);
#endif
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}