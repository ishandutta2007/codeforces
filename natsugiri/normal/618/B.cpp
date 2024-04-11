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

int N;
int A[55][55];
int B[55];
bool X[55];

int main() {
    scanf("%d", &N);
    REP (i, N) REP ( j, N) scanf("%d", A[i]+j);

    for (int c=1; c<=N; c++) {
	REP (k, N) X[k] = (B[k] == 0);

	REP (i, N) REP (j, N) {
	    if (i != j && !B[i] && !B[j]) {
		if (A[i][j] != c) {
		    X[i] = X[j] = false;
		}
	    }
	}

	REP (k, N) if (X[k]) { B[k] = c; break; }
    }

    REP (i, N) printf("%d%c", B[i], i==N-1?'\n':' ');
    
    return 0;
}