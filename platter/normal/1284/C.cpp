#include <cstdio>

long long fac[250001];
long long n,m;

void facfill() {
    fac[0]=1;
    for(int i=1;i<=n;i++) {
        fac[i]=(fac[i-1]*i)%m;
    }
}

long long ans() {
    long long ret=(n*fac[n])%m;
    for(long long i=2;i<=n;i++) {
        ret+=(fac[i]*fac[n-i+1])%m*(n-i+1);
        ret=ret%m;
    }
    return ret;
}

int main(void) {
    scanf("%lld %lld",&n,&m);
    facfill();
    printf("%lld",ans());
    return 0;
}