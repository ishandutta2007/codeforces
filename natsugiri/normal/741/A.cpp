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

LL lcm(LL x, LL y) { return x / __gcd(x, y) * y; }

int N;
int A[1111];
int B[1111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    LL x = 1;
    REP (i, N) {
	int cnt = 0;
	int j = i;
	while (B[j] == 0) {
	    B[j] = 1;
	    j = A[j];
	    cnt++;
	}

	if (i != j) {
	    puts("-1");
	    return 0;
	} else if (cnt) {
	    x = lcm(x, (LL)cnt);
	}
    }

    if (x % 2 == 0) printf("%lld\n", x/2);
    else printf("%lld\n", x);

    return 0;
}