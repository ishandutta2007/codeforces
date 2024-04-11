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

int N, A, B;
int F[111][111];

int main() {
    scanf("%d%d%d", &N, &A, &B);
    if (A*B < N) {
	puts("-1");
	return 0;
    }

    int cur = 1;
    REP (i, A) {
	if (i & 1) {
	    for (int j=B; j--; ) F[i][j] = cur++;
	} else {
	    REP (j, B) F[i][j] = cur++;
	}
    }

    REP (i, A) {
	REP (j, B) {
	    printf("%d%c", (F[i][j] <= N ? F[i][j] : 0), (j==B-1?'\n':' '));
	}
    }

    return 0;
}