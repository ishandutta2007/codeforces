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

int A[6];
int main() {
    REP (i, 6) scanf("%d", A+i);
    LL ans = 0, cur = A[0] * 2 - 1;

    REP (i, A[1] + A[2]) {
	if (i < A[1]) cur++;
	if (i < A[5]) cur++;
	ans += cur;
	if (i >= A[1]) cur--;
	if (i >= A[5]) cur--;
    }

    printf("%lld\n", ans);

    return 0;
}