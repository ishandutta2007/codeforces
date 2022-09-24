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


char S[9];
int main() {
    scanf("%s", S);

    LL g =
	(S[0]-'0') * 10000 +
	(S[2]-'0') * 1000 +
	(S[4]-'0') * 100 +
	(S[3]-'0') * 10 +
	(S[1]-'0') * 1;

    LL ans =powMod(g, 5, 100000);
    printf("%05lld\n", ans);
    
    return 0;
}