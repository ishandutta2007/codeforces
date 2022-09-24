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

LL powll(LL x, LL y) {
    LL r = 1;
    for (;y ;y>>=1) {
	if (y&1) r = r * x;
	x = x* x;
    }
    return r;
}

int main() {
    LL N;
    scanf("%lld", &N);
    LL ans;
    ans = 4LL * 3 * powll(4, N-3) * 2;
    if (N>3) ans += 4LL * 3 * 3 * powll(4, N-4) * (N-3);
    
    printf("%lld\n", ans);
    return 0;
}