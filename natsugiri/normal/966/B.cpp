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

int N;
LL X1, X2;
pair<LL, int> C[300011];

void MAIN() {
    scanf("%d%lld%lld", &N, &X1, &X2);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	C[i].first = x;
	C[i].second = i;
    }

    sort(C, C+N);
    bool yes = true;

    // I1, K1;
    // I2, K2;
    // I1 + K1 + K2 <= N;
    // I2 + K2 + K1 <= N;
    
    int L1 = -1;
    REP (i, N) {
	int K1 = (X1 + C[i].first - 1) / C[i].first;
	if (i + K1 <= N) L1 = K1;
    }

    int L2 = -1;
    REP (i, N) {
	int K2 = (X2 + C[i].first - 1) / C[i].first;
	if (i + K2 <= N) L2 = K2;
    }

    if (L1 == -1 || L2 == -1) {
	yes = false;
    }

    int I1 = -1, I2 = -1;
    if (I1 == -1) {
	REP (i, N) {
	    int K1 = (X1 + C[i].first - 1) / C[i].first;
	    if (i + K1 + L2 <= N) {
		I1 = i;
		I2 = N - L2;
		break;
	    }
	}
    }

    if (I1 == -1) {
	REP (i, N) {
	    int K2 = (X2 + C[i].first - 1) / C[i].first;
	    if (i + K2 + L1 <= N) {
		I2 = i;
		I1 = N - L1;
	    }
	}
    }

    if (I1 == -1) {
	yes = false;
    }

    if (yes) {
	puts("Yes");

	int K1 = (X1 + C[I1].first - 1) / C[I1].first;
	VI v1;
	for (int i=I1; i<I1+K1; i++) v1.push_back(C[i].second+1);
	
	int K2 = (X2 + C[I2].first - 1) / C[I2].first;
	VI v2;
	for (int i=I2; i<I2+K2; i++) v2.push_back(C[i].second+1);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	printf("%d %d\n", K1, K2);
	rprintf("%d", v1.begin(), v1.end());
	rprintf("%d", v2.begin(), v2.end());
    } else {
	puts("No");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}