#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const LL MOD = 1000000009;


LL powMod(LL x, LL y, LL mod) {
    if (y<1) return 1;
    if (y%2) return x*powMod(x, y-1, mod)%mod;
    return powMod(x*x%mod, y/2, mod);
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    LL T = N-M, Z = N-T*K;
    if (Z<0) {
	cout << M << endl;
    } else {
	LL ans = powMod(2, Z/K, MOD)*2*K - 2*K + Z%K;
	
	ans %= MOD;
	ans = (ans + T*(K-1))%MOD;
	ans = (ans + MOD) % MOD;
	cout << ans << endl;
    }
    return 0;
}