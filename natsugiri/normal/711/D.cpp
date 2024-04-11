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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

const LL MOD = 1e9 + 7;

int N, A[200111];
int B[200111], C[200111];

LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    for (; y; y>>=1) {
	if (y&1) r = r * x % m;
	x = x * x % m;
    }
    return r;
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    int ac = 0;
    LL ans = 1;


    REP (i, N) if (B[i] == 0) {
	int v = i;
	int cur = 1;
	while (B[v] == 0) {
	    B[v] = cur++;
	    C[v] = i + 1;
	    v = A[v];
	}

	if (C[v] == i + 1) {
	    int t = cur - B[v];
	    ac += t;
	    ans = ans * (powMod(2, t, MOD) - 2) % MOD;
	}
    }

    ans = ans * powMod(2, N-ac, MOD) % MOD;

    printf("%lld\n", ans);

    return 0;
}