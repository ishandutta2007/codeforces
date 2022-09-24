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
int A[100011];
pair<int, int> P[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int len = 0;
    REP (i, N) {
	if (len == 0 || A[len-1] != A[i]) A[len++] = A[i];
    }

    int ROOP = N;
    N = len;
    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);

    int idx = 0;
    LL ans = 0;
    LL sum = 0;
    for (int r=1; r<=ROOP; r++) {
	while (idx < N && P[idx].first == r) {
	    int i = P[idx].second;
	    int left = (i? A[i-1]: (1<<29));
	    int right = (i+1<N? A[i+1]: (1<<29));
	    if (left < A[i] && A[i] > right) {
		sum -= min(A[i-1], A[i+1]);
	    }

	    int val;
	    if (left > A[i] && A[i] < right) {
		val = 1;
	    } else if (left < A[i] && A[i] > right) {
		val = max(left, right)+1;
	    } else {
		val = min(left, right)+1;
	    }
	    sum += r - val+1;

	    idx++;
	}
	ans += sum;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}