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
int main() {
    scanf("%d%d", &N, &K);
    LL ans = 0;

    if (N / 2 <= K) {
	ans = (LL)N * (N-1) / 2;
    } else {
	LL d = 2LL * N - 3;
	REP (i, K) {
	    ans += d;
	    d -= 4;

	    if (d < 0) break;
	}
    }


    printf("%lld\n", ans);

    return 0;
}