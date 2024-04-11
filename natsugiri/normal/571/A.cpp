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


int A, B, C, L;
LL E(LL x) {
    return (x+3) * (x+2) * (x+1) / 6;
}
LL F(LL x) {
    if (x < -2) return 0;
    return (x+2) * (x+1) / 2;
}
LL calc() {
    LL r = 0;
    REP (x, L+1) {
	LL t = min(A-B-C+x, L-x);
	r += F(t);
    }
    return r;
}

int main() {
    scanf("%d%d%d%d", &A, &B, &C, &L);
    LL ans = E(L);
    ans -= calc();
    swap(A, B);
    ans -= calc();
    swap(A, C);
    ans -= calc();
    printf("%lld\n", ans);
    return 0;
}