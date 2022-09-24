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

int N, A[100011];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	LL x = 1LL<<60;
	if (i>0) amin(x, (LL)A[i]-A[i-1]);
	if (i+1<N) amin(x, (LL)A[i+1]-A[i]);
	printf("%lld ", x);
	x = max((LL)A[i]-A[0], (LL)A[N-1]-A[i]);;
	printf("%lld\n", x);
    }

    return 0;
}