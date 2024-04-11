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

int N;
int X[200111], Y[200111];
pair<int, int> P[200111];

template<class T> LL calc(T *Z) {
    sort(Z, Z+N);
    LL ans = 0;
    int end = 0;
    LL t;
    REP (i, N) {
	if (Z[i] != Z[end]) {
	    t = i - end;
	    ans += t * (t-1) / 2;
	    end = i;
	}
    }

    t = N - end;
    ans += t * (t-1) / 2;
    return ans;
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", X+i, Y+i), P[i] = make_pair(X[i], Y[i]);
    LL ans = calc(X) + calc(Y) - calc(P);

    printf("%lld\n", ans);

    return 0;
}