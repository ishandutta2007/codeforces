#include<cassert>
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
LL N, M;
LL N_mod, inv = (MOD+1)/2;

int main() {
    scanf("%lld%lld", &N, &M);

    N_mod = N % MOD;
    
    LL ans = 0;
    LL i = 1;
    for (; i<=M && i*i<=N; i++) {
	LL q = N / i;
	ans += N_mod - (q % MOD) * i;
	ans %= MOD;
    }

    for (LL q=N/i; q>0 && i <= M; q--) {
	LL c = N/q - N/(q+1);
	// [i, i+c)
	if (i + c > M) {
	    c = M-i+1;
	}

	// N - q * i;
	// ...;
	// N - q * (i+c-1);
	LL c_mod = c % MOD;
	ans += N_mod * c_mod - (q % MOD) * ((2*i + c_mod - 1) % MOD) % MOD * c_mod % MOD * inv;
	ans %= MOD;

	i += c;
    }

    if (i <= M) {
	// assert(i == N+1);
	ans += N_mod * ((M-i+1) % MOD);
	ans %= MOD;
    }

    ans = (ans % MOD + MOD) % MOD;
    printf("%d\n", (int)ans);

    return 0;
}