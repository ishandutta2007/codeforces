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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

LL gcd(LL x, LL y) {
    while (y) {
	x %= y;
	swap(x, y);
    }
    return x;
}
LL lcm(LL a, LL b) { return a/gcd(a, b)*b; }

LL C, Ha, Hb, Wa, Wb;
const int MAX = 2000011;
LL dp[MAX];
int main() {
    scanf("%lld%lld%lld%lld%lld", &C, &Ha, &Hb, &Wa, &Wb);
    if (Wa > Wb) {
	swap(Wa, Wb);
	swap(Ha, Hb);
    }
    LL best = 0;
    if (Wb <= 1000) {
	LL L = lcm(Wa, Wb), Z = max(L/Wa*Ha, L/Wb*Hb);
	for (int i=0; i+Wa < MAX; i++) amax(dp[i+Wa], dp[i]+Ha);
	for (int i=0; i+Wb < MAX; i++) amax(dp[i+Wb], dp[i]+Hb);
	for (int i=0; i<MAX && i<=C; i++)
	    amax(best, dp[i] + (C-i)/L*Z);

    } else {
	for (LL s=0, t=0; s<=C; s+=Wb, t+=Hb)
	    amax(best, t + (C-s)/Wa*Ha);
    }
    printf("%lld\n", best);
    return 0;
}