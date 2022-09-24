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

int N, A[200111];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    int m = *min_element(A, A+N);

    int last = 0;
    int ans = 0;
    REP (i, 2*N) {
	if (A[i%N] == m) {
	    amax(ans, i - last);
	    last = i+1;
	}
    }

    printf("%lld\n", ans + (LL)m * N);
    return 0;
}