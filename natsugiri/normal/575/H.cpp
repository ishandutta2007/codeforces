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

const LL MOD = 1000000007;
const int MAX = 3000000;
LL inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i % MOD;
	fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

LL nCk(int n, int k) {
    return fact[n] * fact_inv[k] % MOD * fact_inv[n-k] % MOD;
}

int N;
int main() {
    init();
    scanf("%d", &N);
    LL ans = (nCk(2*N+2, N+1) - 1 + MOD) % MOD;
    printf("%d\n", (int)ans);

    return 0;
}