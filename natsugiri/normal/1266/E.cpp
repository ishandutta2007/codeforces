#include<tuple>
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
int A[200011];
int B[200011];

using Tuple = tuple<int, int, int>;
Tuple X[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int Q;
    scanf("%d", &Q);
    vector<Tuple> sortedX;
    sortedX.reserve(Q);

    REP (i, Q) {
	int s, t, u;
	scanf("%d%d%d", &s, &t, &u);
	s--; u--;
	X[i] = Tuple(s, t, u);
	sortedX.emplace_back(s, t, -1);
    }

    sort(sortedX.begin(), sortedX.end());
    sortedX.erase(unique(sortedX.begin(), sortedX.end()), sortedX.end());

    LL sum = 0;
    REP (i, N) sum += A[i];

    REP (i, Q) {
	int s, t, u;
	tie(s, t, u) = X[i];

	auto it = lower_bound(sortedX.begin(), sortedX.end(), Tuple(s, t, -1));
	int s0, t0, u0;
	tie(s0, t0, u0) = *it;

	if (0 <= u0) {
	    sum -= max(0, A[u0] - B[u0]);
	    B[u0]--;
	    sum += max(0, A[u0] - B[u0]);
	}
	if (0 <= u) {
	    sum -= max(0, A[u] - B[u]);
	    B[u]++;
	    sum += max(0, A[u] - B[u]);
	}
	*it = Tuple(s, t, u);

	printf("%lld\n", sum);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}