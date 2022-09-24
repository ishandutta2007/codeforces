#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD=1000000007;
int a, b, n;
LL fact[1000010];
bool good(int x) {
    for (;x;) {
	if (x%10!=a && x%10!=b) return false;
	x/=10;
    }
    return true;
}
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
LL nCk(int n, int k) {
    return fact[n] * invMod(fact[k]*fact[n-k] % MOD, MOD) % MOD;
}

int main() {
    fact[0]=1;
    for (int i=1; i<1000010; i++) fact[i]=fact[i-1]*i%MOD;
    
    scanf("%d%d%d", &a, &b, &n);
    LL ans=0;
    for (int i=0; i<=n; i++) {
	int x=a*i+b*(n-i);
	if (good(x)) {
	    ans = (ans+nCk(n, i))%MOD;
	}
    }
    printf("%d\n", int(ans));
    return 0;
}