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

int N, T;
int A[111];
const int SIZE = 30011;
int lis[SIZE+1];
int lis2[SIZE+1];
int cnt[333];

int main() {
    scanf("%d%d", &N, &T);
    REP (i, N) scanf("%d", A+i);

    if (T == 0) {
	puts("0");
    } else if (T < 300) {
	memset(lis, 0x3f, sizeof lis);
	REP (t, T) REP (i, N) *upper_bound(lis, lis+SIZE, A[i]) = A[i];
	int ans = lower_bound(lis, lis+SIZE, lis[SIZE]) - lis;
	printf("%d\n", ans);
    } else {
	memset(lis, 0x3f, sizeof lis);
	memset(lis2, 0x3f, sizeof lis2);
	int D = 110;
	REP (t, D) REP (i, N) *upper_bound(lis, lis+SIZE, A[i]) = A[i];
	REP (t, D) REP (i, N) *upper_bound(lis2, lis2+SIZE, -A[N-1-i]) = -A[N-1-i];
	REP (i, N) cnt[A[i]]++;

	LL ans = 0;
	REP (i, N) {
	    LL l = upper_bound(lis, lis+SIZE, A[i]) - lis;
	    LL r = upper_bound(lis2, lis2+SIZE, -A[i]) - lis2;
	    amax(ans, l + r + (LL)cnt[A[i]] * (T-2*D));
	}
	printf("%lld\n", ans);
	
    }
    return 0;
}