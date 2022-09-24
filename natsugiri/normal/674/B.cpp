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
int A[4];
int B[1111], I;

int main() {
    scanf("%d%d", &N, &K);
    REP (i, 4) scanf("%d", A+i), A[i]--;

    if (N + 1 <= K && N > 4) {
	REP (i, N) {
	    if (count(A, A+4, i) == 0) B[I++] = i;
	}

	REP ($, 2) {
	    printf("%d %d ", A[0] + 1, A[2] + 1);
	    REP (i, I) printf("%d ", B[i] + 1);
	    printf("%d %d\n", A[3] + 1, A[1] + 1);
	    swap(A[0], A[2]);
	    swap(A[1], A[3]);
	}
    } else {
	puts("-1");
    }


    return 0;
}