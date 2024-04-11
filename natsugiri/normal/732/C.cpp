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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

LL A[3];

int main() {
    REP (i, 3) scanf("%lld", A+i);
    LL m = *max_element(A, A+3);
    LL ans = m * 3;

    REP (S, 8) {
	bool yes = true;
	LL tmp = 0;
	REP (i, 3) {
	    if (~S & (1 << i) && A[i] == m) yes = false;

	    if (S & (1 << i)) tmp += m - A[i];
	    else tmp += m - 1 - A[i];
	}

	if (yes) {
	    amin(ans, tmp);
	}
    }


    printf("%lld\n", ans);
    return 0;
}