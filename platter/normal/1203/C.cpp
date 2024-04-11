#include <cstdio>

long long gcd(long long a,long long b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

long long cnt(long long x) {
    long long ret=1;
    for(long long i=2;i*i<=x;i++) {
        long long k=1;
        while (x%i==0) {
            x/=i;
            k++;
        }
        ret*=k;
    }
    if (x!=1) {
        ret*=2;
    }
    return ret;
}

int main(void) {
    int n;
    scanf("%d\n",&n);
    long long arr[400000];
    for(int i=0;i<n;i++) {
        scanf("%lld ",&arr[i]);
    }
    if (n==1) {
        printf("%lld",cnt(arr[0]));
        return 0;
    }
    long long val=gcd(arr[0],arr[1]);
    for(int i=2;i<n;i++) {
        val=gcd(val,arr[i]);
    }
    printf("%lld",cnt(val));
    return 0;
}