#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, K;
int A[100111], B[100111];

bool ok(LL m) {
    LL lack = 0;
    LL more = 0;
    REP (i, N) {
	if (A[i] * m > B[i]) {
	    lack += A[i] * m - B[i];
	} else {
	    more += B[i] - A[i] * m;
	}
    }
    return lack <= K;
}


int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    LL lo = 0, hi = 1LL<<60;
    REP (i, N) amin(hi, ((LL)B[i] + K)/A[i]);
    hi++;

    while (hi - lo > 1) {
	LL mid = (hi + lo) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    printf("%lld\n", lo);

    return 0;
}