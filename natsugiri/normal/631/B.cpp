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

int N, M, K;

int R[5111], Rx[5111], C[5111], Cx[5111];

int main() {

    scanf("%d%d%d", &N, &M, &K);
    REP (i, K) {
	char op[5];
	scanf("%s", op);
	if (op[0] == '1') {
	    int r, a;
	    scanf("%d%d", &r, &a);
	    r--;
	    R[r] = i+1;
	    Rx[r] = a;
	} else {
	    int c, a;
	    scanf("%d%d", &c, &a);
	    c--;
	    C[c] = i+1;
	    Cx[c] = a;
	}
    }

    REP (i, N) {
	REP (j, M) {
	    printf("%d%c", R[i] > C[j]? Rx[i]: Cx[j], j==M-1?'\n':' ');
	}
    }

    return 0;
}