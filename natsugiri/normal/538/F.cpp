#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, A[200011];
int ans[200011];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    int R = sqrt(N)+0.1;
    for (int i=1; i<N; i++) {
	for (int k=1; k<R; k++) {
	    if (A[(i-1)/k] > A[i]) {
		ans[k]++;
		ans[k+1]--;
	    }
	}
	for (int k=R; k<N; ) {
	    // A[(i-1)/k] > A[i]
	    // (i-1)/k > (i-1)/x
	    int t = (i-1)/k;
	    int x = N;
	    if (t != 0) x = min(N, (i-1)/t+1);
	    if (A[(i-1)/k] > A[i]) {
		ans[k]++;
		ans[x]--;
	    }
	    k = x;
	}
    }
    
    REP (i, N) ans[i+1] += ans[i];
    for (int i=1; i<N; i++) printf("%d%c", ans[i], i+1==N?'\n':' ');
    return 0;
}