#include<map>
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


int N, K, A[200011];
map<LL, int> L, R;
int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) R[A[i]]++;
    LL ans = 0;
    REP (i, N) {
	R[A[i]]--;
	if (A[i] % K == 0) {
	    ans += (LL)L[A[i]/K] * R[(LL)A[i]*K];
	}
	L[A[i]]++;
    }

    printf("%lld\n", ans);
    
    return 0;
}