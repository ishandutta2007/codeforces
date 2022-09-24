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

LL K;
int N;
LL A[111];
LL B[111];

void MAIN() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%lld", A+i);
    sort(A, A+N);

    vector<LL> D;
    REP (i, 100) D.push_back(i+1);

    REP (i, N) {
	for (LL d=101; d*d <= A[i]; d++) {
	    D.push_back(d);
	}
	for (LL b=1; b*b <= A[i]; b++) {
	    LL t = (A[i] + b - 1) / b;
	    if (t >= 100) {
		D.push_back(t);
	    }
	}
    }

    D.push_back(A[N-1] + 2 * K);

    sort(D.begin(), D.end());
//    D.erase(unique(D.begin(), D.end()), D.end());

    LL ans = 1;

    REP (z, (int)D.size()-1) {
	LL d = D[z], up = D[z+1];

	if (d == up) continue;

	REP (i, N) {
	    B[i] = (A[i] + d - 1) / d;
	    // B[i] * (up-1) - A[i] <= K
	    // up-1 <= (K + A[i]) / B[i];
	    amin(up, (K+A[i]+B[i]) / B[i] + 1);
	}

	if (up <= d) continue;

	while (up - d > 1) {
	    LL mid = (up + d) / 2;
	    LL cost = 0;
	    REP (i, N) cost += B[i] * mid - A[i];

	    if (cost <= K) d = mid;
	    else up = mid;
	}

	{
	    LL cost = 0;
	    REP (i, N) cost += B[i] * d - A[i];
	    if (cost <= K) amax(ans, d);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}