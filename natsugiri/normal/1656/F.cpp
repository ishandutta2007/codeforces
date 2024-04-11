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
LL A[200011];

void MAIN() {
//    for (int t=-5; t<=5; t++) {
//	// LL a[] = {-1, 2-3*t, -2-t};
//	LL a[] = {-3+2*t, 2-3*t, -6+t};
//	sort(a, a+3);
//	printf("%d [%lld], ", t, a[0] + a[1]);
//	rprintf("%lld", a, a+3);
//    }
//    exit(0);
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    LL ma = *max_element(A, A+N);
    LL mi = *min_element(A, A+N);

    LL sum = 0;
    REP (i, N) sum += A[i];
    LL high = sum + ma * (N-2);
    LL low = sum + mi * (N-2);
    if (0 < low && 0 < high) {
	puts("INF");
    } else if (0 > low && 0 > high) {
	puts("INF");
    } else {
	sort(A, A+N);
	vector<LL> B;
	for (int i=1; i<N-1; i++) B.push_back(A[i]);
	LL sumB = 0;
	REP (i, B.size()) sumB += B[i];

	LL Z[3];
	LL leftB = 0;
	LL ans = -(1LL<<62);
	REP (i, (int)B.size()+1) {
	    LL rightB = sumB - leftB;

	    Z[0] = leftB * A[N-1] + rightB * A[0] + A[0] * A[N-1];
	    Z[1] = leftB + i * A[N-1] + rightB + ((LL)B.size()-i) * A[0] + A[0] + A[N-1];

	    // B[i]+t <= 0 && 0 <= B[i+1]+t;
	    LL low, high;
	    if (i) high = -B[i-1];
	    else high = -A[0];

	    if (i < (int)B.size()) low = -B[i];
	    else low = -A[N-1];

	    // printf("%lld %lld\n", Z[0] + Z[1] * low, Z[0] + Z[1] * high);
	    amax(ans, Z[0] + Z[1] * low);
	    amax(ans, Z[0] + Z[1] * high);

	    if (i == (int)B.size()) break;

	    leftB += B[i];
	}
	printf("%lld\n", ans);

    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}