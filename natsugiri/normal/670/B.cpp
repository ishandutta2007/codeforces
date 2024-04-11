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
LL K;
int A[100111];


int main() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%d", A+i);
    K--;
    REP (i, N) {
	if (K <= i) {
	    printf("%d\n", A[K]);
	    return 0;
	}
	K -= i + 1;
    }


    return 0;
}