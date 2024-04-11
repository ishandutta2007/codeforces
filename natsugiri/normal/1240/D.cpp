#include<map>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[300011];
int dp[300011];
map<int, int> mp[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N+1) mp[i].clear();

    LL ans = 0;
    REP (i, N) {
	if (i > 0 && A[i-1] == A[i]) {
	    dp[i+1] = dp[i-1]+1;
	    swap(mp[i+1], mp[i-1]);
	} else {
	    auto it = mp[i].find(A[i]);
	    if (it != mp[i].end()) {
		int j = it->second;
		dp[i+1] = dp[j]+1;
		swap(mp[i+1], mp[j]);
	    } else {
		dp[i+1] = 0;
	    }
	}
	mp[i+1][A[i]] = i;
	ans += dp[i+1];
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}