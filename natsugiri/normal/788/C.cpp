#include<bitset>
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

int T, K;
int A[1000111];

const int BASE = 1024 * 2;
const int SIZE = BASE * 2;
typedef bitset<SIZE> Bits;
Bits B[2];

int main() {
    scanf("%d%d", &T, &K);
    REP (i, K) scanf("%d", A+i);

//    K = 1000;
//    REP (i, K) A[i] = i + 1;

    sort(A, A+K);
    K = unique(A, A+K) - A;

    int ans = -1;
    if (count(A, A+K, T)) ans = 1;

    if (ans == -1 && A[0] < T && T < A[K-1]) {
	int cur = 0, nxt = 1;
	B[cur].set(BASE);

	REP (t, 1011) {
	    B[nxt].reset();

	    REP (i, K) {
		int diff = A[i] - T;
		if (diff >= 0) B[nxt] |= B[cur] << diff;
		else B[nxt] |= B[cur] >> -diff;
	    }

	    if (B[nxt].test(BASE)) {
		ans = t + 1;
		break;
	    }

	    swap(cur, nxt);
	}
    }

    printf("%d\n", ans);

    return 0;
}