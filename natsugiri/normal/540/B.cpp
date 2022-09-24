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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, K, P, X, Y, A[1111], B[1111];
int S;
int main() {
    scanf("%d%d%d%d%d", &N, &K, &P, &X, &Y);
    REP (i, K) scanf("%d", A+i);

    REP (i, N-K+1) {
	REP (j, K) B[j] = A[j];
	REP (j, N-K) B[j+K] = (j<i ? 1: Y);
	sort(B, B+N);
	S = 0;
	REP (j, N) S += B[j];
	if (S <= X && B[N/2] >= Y) {
	    REP (j, N-K) printf("%d%c", (j<i ? 1: Y), j+1==N-K?'\n':' ');
	    return 0;
	}
    }
    puts("-1");
    
    return 0;
}