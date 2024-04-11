#include <cstdio>
#include <algorithm>
using namespace std;

const long long one=1;
long long n,k;

long long oddcount(long long x) {
    long long savex=x;
    int times=0;
    long long ret=0;
    while (x<=n) {
        ret+=(one<<times);
        x=2*x+1;
        times+=1;
    }
    long long temp=savex<<times;
    if (n-temp+1>0) {
        ret+=n-temp+1;
    }
    return ret;
}

long long evencount(long long x) {
    return oddcount(x)+oddcount(x+1);
}

long long oddans() {
    long long lo=0;
    long long hi=n/2;
    long long mid=(lo+hi)/2;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        if (oddcount(2*mid+1)>=k&&oddcount(2*mid+3)<k) {
            return 2*mid+1;
        }
        if (oddcount(2*mid+1)<k) {
            hi=mid-1;
        }
        else {
            lo=mid+1;
        }
    }
    return -1;
}

long long evenans() {
    long long lo=1;
    long long hi=n/2;
    long long mid=(lo+hi)/2;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        if (evencount(2*mid)>=k&&evencount(2*mid+2)<k) {
            return 2*mid;
        }
        if (evencount(2*mid)<k) {
            hi=mid-1;
        }
        else {
            lo=mid+1;
        }
    }
    return 0;
}

int main(void) {
    scanf("%lld %lld",&n,&k);
    printf("%lld",max(oddans(),evenans()));
    return 0;
}