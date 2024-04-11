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

char A[111];
int N, P, Q;

    
int main() {
    scanf("%d%d%d%s", &N, &P, &Q, A);

    REP (i, N+1) {
	int t = N - P * i;
	if (t >= 0 && t % Q == 0) {
	    t /= Q;
	    printf("%d\n", i + t);
	    
	    REP (j, i) {
		REP (k, P) putchar(A[j*P+k]);
		putchar('\n');
	    }
	    REP (j, t) {
		REP (k, Q) putchar(A[i*P+j*Q+k]);
		putchar('\n');
	    }
	    return 0;
	}
    }

    puts("-1");
    return 0;
}