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


LL nCk(int n, int k) {
    LL ret = 1;
    REP (i, k) ret = ret * (n - i) / (i + 1);
    return ret;
}


LL N, T;

int main() {
    scanf("%lld%lld", &N, &T);
    N++;

    if (T & (T-1)) {
	puts("0");
	return 0;
    }
    int P = 0;
    for (; ~T & (1LL<<P); P++) ;

    LL ans = 0;
    if (T == 1) ans = -1;

    LL len = 1;
    REP (i, 99) {
	if (len > N) {
	    while (N) {
		i--; len /= 2;
		if (len <= N) {
		    if (P >= 0 && i >= P) ans += nCk(i, P);
		    N -= len;
		    P--;
		}
	    }
	    break;
	}

	if (i >= P) ans += nCk(i, P);
	N -= len;
	len *= 2;
    }

    printf("%lld\n", ans);

    return 0;
}