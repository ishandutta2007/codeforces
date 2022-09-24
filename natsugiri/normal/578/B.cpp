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

int N, A[200111], K, X;
int L[200111], R[200111];
int main() {
    scanf("%d%d%d", &N, &K, &X);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	L[i+1] = L[i] | A[i];
	R[N-1-i] = R[N-i] | A[N-1-i];
    }

    LL ans = 0;
    LL C = 1;
    REP (i, K) C *= X;
    REP (i, N) {
	amax(ans, L[i] | R[i+1] | (A[i] * C));
    }
    printf("%lld\n", ans);
    return 0;
}