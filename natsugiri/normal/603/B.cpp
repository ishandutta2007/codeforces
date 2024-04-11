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

const LL MOD = 1e9+7;
LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    for (; y; y>>=1) {
	if (y&1) r = r * x % m;
	x = x * x % m;
    }
    return r;
}

int P, K;
bool use[1000111];
int main() {
    scanf("%d%d", &P, &K);

    LL ans;
    if (K == 0) {
	ans = powMod(P, P-1, MOD);
    } else {

	if (K == 1) ans = P;
	else ans = 1;
	
	for (int i=1; i<P; i++) {
	    if (use[i]) continue;

	    ans = ans * P % MOD;
	    
	    LL cur = i;
	    do {
		use[cur] = true;
		cur = cur*K % P;
	    } while (cur != i);
	}
    }

    printf("%lld\n", ans);
    return 0;
}