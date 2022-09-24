#include<cassert>
#include<complex>
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


int N, M;
// 2 ^ 17


int TEST = 0;
double dp[1<<17];

int main() {
    if (TEST) {
	N = 100;
	M = 1;
    }else {
	scanf("%d%d", &N, &M);
    }
    
    double pp = (double)1.0 / (M-1);

    dp[0] = M-1;
    
    int score = 0;

    // 0 n-1
    REP (_, N) {
	int x;

	if (TEST) {
	    x = M/2+1;
	    x = M;
	} else {
	    scanf("%d", &x);
	}
	
	score += x;

	double cur = 0;
	int limit = (_+1) * M + 10;
	int le = limit, ri = limit;
	for (int i=limit; i--; ) {
	    int lo = 1, hi = min(i, M);
	    double val = 0;
	    int le_ = max(0, i-hi), ri_ = i-lo;

	    while (ri >= 0 && ri > ri_) cur -= dp[ri--];
	    while (le >  0 && le > le_) cur += dp[--le];

	    if (ri_ < le_) val = 0;
	    else {
		val = cur;
		if (le_ <= i-x && i-x <= ri_) val -= dp[i-x];
		val *= pp;
	    }

	    dp[i] = val;
	}

    }

    if (M == 1) {
	puts("1.00000000000000");
    } else {
	double ans = 0;
	REP (i, score) ans += dp[i];
	printf("%.20f\n", (ans + 1));
    }
    return 0;
}