#include <cstdio>

long long gcd(long long a,long long b) {
    if (b==0)
    return a;
    return gcd(b,a%b);
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        long long a,m;
        scanf("%lld %lld\n",&a,&m);
        m/=gcd(a,m);
        long long ret=m;
        for(long long i=2;i*i<=m;i++) {
            if (m%i==0) {
                ret/=i;
                ret*=(i-1);
            }
            while(m%i==0) {
                m/=i;
            }
        }
        if (m!=1) {
            ret/=m;
            ret*=(m-1);
        }
        printf("%lld\n",ret);
    }
}