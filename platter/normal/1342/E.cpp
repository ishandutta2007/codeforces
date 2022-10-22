#include <bits/stdc++.h>
using namespace std;

int n,k;
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

long long fac[200005];

long long comb(int n,int k) {
    long long ret=fac[n];
    ret*=fastpow(fac[k],mod-2);
    ret%=mod;
    ret*=fastpow(fac[n-k],mod-2);
    ret%=mod;
    return ret;
}

int main(void) {
    fac[0]=1;
    for(int i=1;i<200005;i++) {
        fac[i]=(fac[i-1]*i)%mod;
    }
    scanf("%d %d\n",&n,&k);
    if (k>=n) {
        printf("0");
        return 0;
    }
    int use=n-k;
    if (use==n) {
        printf("%lld",fac[n]);
        return 0;
    }
    long long ret=0;
    for(int i=use;i>=1;i--) {
        long long p=(i%2==use%2?1:mod-1);
        long long val=comb(use,i)*fastpow(i,n);
        val%=mod;
        val*=p;
        val%=mod;
        ret+=val;
        ret%=mod;
    }
    ret*=comb(n,use);
    ret*=2;
    ret%=mod;
    printf("%lld",ret);
}