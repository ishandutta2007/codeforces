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

int N, P[333];
char A[333][333];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);
    REP (i, N) scanf("%s", A[i]);

    REP (k, N) REP (i, N) REP (j, N) A[i][j] |= (A[i][k] & A[k][j]);

    // REP (i, N) puts(A[i]);

    REP (i, N) {
	for (int j=i+1; j<N; j++) {
	    if (A[i][j]=='1' &&  P[j] < P[i]) {
		swap(P[i], P[j]);
	    }
	}
    }

    REP (i, N) printf("%d%c", P[i], i==N-1 ? '\n' : ' ');
    
    return 0;
}