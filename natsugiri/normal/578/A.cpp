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

int A, B;
int main() {
    scanf("%d%d", &A, &B);
    if (A < B) puts("-1");
    else {
	double ans;
	if (A % B == 0 && A / B % 2 == 1) {
	    ans = B;
	} else {
	    // (2KB+B, B), (A, B), (2KB+3B, B);
	    // (2Kt+t, t), (2Kt+2t, 0);
	    // y = -x + 2Kt+2t;
	    // B = -A + 2Kt+2t;
	    //(2k+2)t = B+A;
	    double K = (A-B)/(2LL*B);
	    // eprintf("%f %f\n", 2*K*B+B, 2*K*B+2*B);
	    ans = ((double)B+A) / (2.0*K+2);
	}
	printf("%.20f\n", ans);
    }
    return 0;
}