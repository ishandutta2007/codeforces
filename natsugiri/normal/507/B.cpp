#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

LL sq(LL x) { return x*x; }

LL R, X0, Y0, X1, Y1;
int main() {
    scanf("%lld%lld%lld%lld%lld", &R, &X0, &Y0, &X1, &Y1);
    LL D2 = sq(X0-X1) + sq(Y0-Y1);
    LL lo = -1, hi = sqrt(D2)/R + 100;
    for (; hi - lo > 1;) {
	LL m = (lo + hi) /2;
	LL w = sq(2 * R * m);
	if (w < D2) lo = m;
	else hi = m;
    }
    printf("%d\n", (int)hi);
    return 0;
}