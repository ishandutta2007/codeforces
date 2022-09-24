#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

LL extgcd(LL a, LL b, LL &x, LL &y) { // a x + b y = gcd(a, b)
    LL g=a; x=1, y=0;
    if (b) { g=extgcd(b, a%b, y, x); y-=a/b*x; }
    return g;
}

LL invMod(LL a, LL mod) {
    LL x, y;
    if (extgcd(a, mod, x, y) == 1) return (x + mod) % mod;
    return 0; // unsolvable
}

LL fact[200010], fact_inv[200010];
LL nCk(int n, int k) {
    return fact[n] * fact_inv[k] % MOD * fact_inv[n-k] % MOD;
}


int N, M, G;
int main() {
    fact[0] = 1;
    for (int i=1; i<200010; i++) fact[i] = fact[i-1]*i%MOD;
    for (int i=0; i<200010; i++) fact_inv[i] = invMod(fact[i], MOD);
    
    
    scanf("%d%d%d", &N, &M, &G);
    LL Z=0;
    if (M==0) {
	Z = N%2;
    } else {
	for (int i=0; i<N; i+=2) {
	    Z = (Z + nCk(N-i+M-1, M-1)) % MOD;
	}
	if (N%2==0) {
	    if (M!=1) Z = (Z+1)%MOD;
	} else {
	    if (M==1) Z = (Z+1)%MOD;
	}
    }
	
    
    printf("%d\n", G==0 ? int(Z) : int((nCk(N+M, N) - Z + MOD) % MOD));
    return 0;
}