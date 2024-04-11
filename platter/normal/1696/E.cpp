#include <bits/stdc++.h>
using namespace std;

int n;
int a[200002];
long long fac[500001];
const int mod=1e9+7;

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

long long comb(int a,int b) {
    if (a<b) {
        return 0;
    }
    long long ret=fac[a];
    ret*=fastpow(fac[b],mod-2);
    ret%=mod;
    ret*=fastpow(fac[a-b],mod-2);
    return ret%mod;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    if (a[0]==0) {
        printf("0");
        return 0;
    }
    fac[0]=1;
    for(int i=1;i<=500000;i++) {
        fac[i]=(fac[i-1]*i)%mod;
    }
    long long ret=mod-1;
    for(int i=0;i<=n;i++) {
        long long cnt=0;
        cnt=comb(a[i]+i-1,i);
        if (true) {
            cnt+=comb(a[i]+i,i+1)-comb(a[i+1]+i,i+1);
            cnt+=mod;
            cnt%=mod;
        }
        //printf("%lld\n",cnt);
        ret+=cnt;
        ret%=mod;
    }
    printf("%lld",ret);
    return 0;
}