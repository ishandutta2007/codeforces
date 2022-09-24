#include<set>
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

int N, A[500111], B[500111];
bool f[500111];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int ans = 0;
    int last = 0;
    B[0] = A[0];
    B[N-1] = A[N-1];
    
    for (int i=0; i<N; i++) {
	if (A[i] == A[i+1] || i==N-1) {
	    amax(ans, (i-last)/2);
	    if (A[last] == A[i]) {
		for (int j=last; j<=i; j++) B[j] = A[last];
	    } else {
		for (int j=last; j<=i; j++) {
		    if (j-last < i-j) B[j] = A[last];
		    else B[j] = A[i];
		}
	    }
	    last = i+1;
	}
    }

    printf("%d\n", ans);
    REP (i, N) printf("%d%c", B[i], i+1==N? '\n': ' ');
    
    return 0;
}