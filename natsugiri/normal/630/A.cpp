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

LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    for (;y ;y>>=1) {
	if (y&1) r = r * x % m;
	x = x* x % m;
    }
    return r;
}

LL N;
int main() {
    scanf("%lld", &N);
    printf("%02lld\n", powMod(5,N,100));
    return 0;
}