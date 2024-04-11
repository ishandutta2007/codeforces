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

int N, T[5111];
int C[5111];
int ans[5111];


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", T+i);

    REP (i, N) {
	pair<int, int> B(0, 0);
	memset(C, 0, sizeof C);
	for (int j=i; j<N; j++) {
	    C[T[j]]++;
	    pair<int, int> k(-C[T[j]], T[j]);
	    amin(B, k);
	    ans[B.second]++;
	}
    }
    REP (i, N) printf("%d%c", ans[i+1], i==N-1?'\n':' ');


    return 0;
}