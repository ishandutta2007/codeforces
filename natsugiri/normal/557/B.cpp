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

int N, W;
int A[200011];
int main() {
    scanf("%d%d", &N, &W);
    REP (i, N*2) scanf("%d", A+i);
    sort(A, A+N*2);

    double best = A[0];
    REP (i, N) {
	amin(best, (double)A[i]);
	amin(best, A[i+N] * 0.5);
    }
    best = best * N * 3;
    amin(best, (double)W);
    printf("%.9f\n", best);
    return 0;
}