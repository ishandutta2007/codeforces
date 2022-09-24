#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<bitset>

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
int A[111];


const int SIZE = 200000;
using Bits = bitset<SIZE*2>;
Bits B;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int g = 0;
    REP (i, N) g = __gcd(g, A[i]);
    REP (i, N) A[i] /= g;

    int sum = 0;
    REP (i, N) sum += A[i];

    int ans = -1;

    if (sum % 2 == 1) {

    } else {
	B.set(SIZE);
	REP (i, N) {
	    B = (B << A[i]) | (B >> A[i]);
	}

	if (B.test(SIZE)) {
	    REP (i, N) if (A[i] % 2) {
		ans = i;
		break;
	    }
	}
    }

    if (ans == -1) {
	puts("0");
    } else {
	puts("1");
	printf("%d\n", ans+1);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}