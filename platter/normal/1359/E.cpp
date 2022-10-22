#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;

long long fastpow(long long a,long long b) {
    if (b==0) {
        return 1;
    }
    if (b%2==1) {
        return (fastpow(a,b-1)*a)%mod;
    }
    long long half=fastpow(a,b/2);
    return (half*half)%mod;
}

long long fac[500001];
long long inv[500001];

long long comb(int a,int b) {
    if (a<b) {
        return 0;
    }
    long long ret=fac[a];
    ret*=inv[b];
    ret%=mod;
    ret*=inv[a-b];
    ret%=mod;
    return ret;
}

int main(void) {
    int n,k;
    scanf("%d %d",&n,&k);
    if (k>n) {
        printf("0");
        return 0;
    }
    fac[0]=1;
    for(int i=1;i<=500000;i++) {
        fac[i]=(fac[i-1]*i)%mod;
    }
    inv[500000]=fastpow(fac[500000],mod-2);
    for(int i=499999;i>=0;i--) {
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
    long long ret=0;
    for(int i=1;i<=n;i++) {
        ret+=comb(n/i-1,k-1);
	ret%=mod;
    }
    printf("%lld",ret);
}