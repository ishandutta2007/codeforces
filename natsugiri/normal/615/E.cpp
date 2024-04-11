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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const LL dx[] = { -1, -2, -1, 1, 2, 1 };
const LL dy[] = { +2, 0, -2, -2, 0, +2};
LL N;
int main() {
    scanf("%lld", &N);
    LL lo = 0, hi = 1e9;

    while (hi - lo > 1) {
	LL m = (hi + lo) / 2;
	if (m * (m+1) * 3 > N) hi = m;
	else lo = m;
    }

    N -= lo * (lo + 1) * 3;

    if (N == 0) {
	printf("%lld 0\n", 2*lo);
    } else {
	LL x = 2*lo+2, y = 0;

	REP (d, 6) {
	    LL g = min(N, hi);
	    x += dx[d] * g;
	    y += dy[d] * g;
	    N -= g;
	}

	printf("%lld %lld\n", x, y);
    }
    return 0;
}