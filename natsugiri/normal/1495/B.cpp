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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int P[100011];
int L[100011];
int R[100011];

int ma, cnt;
void update(int x) {
    if (ma < x) {
	ma = x;
	cnt = 0;
    }
    if (ma == x) cnt++;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i), P[i]--;

    for (int i=1; i<N; i++) {
	if (P[i-1] < P[i]) L[i] = L[i-1] + 1;
    }
    for (int i=N-2; i>=0; i--) {
	if (P[i] > P[i+1]) R[i] = R[i+1] + 1;
    }

    ma = -1;
    int b = -1;

    REP (i, N) {
	update(L[i]);

	update(R[i]);


	if (L[i] == R[i] && L[i] % 2 == 0) {
	    amax(b, L[i]);
	}
    }

    if (b == ma && cnt == 2) {
	puts("1");
    } else {
	puts("0");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}