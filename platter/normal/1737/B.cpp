#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    if (x==0) {
        return 0;
    }
    long long a=floor(sqrt(x));
    if (a*a>x) {
        a--;
    }
    if ((a+1)*(a+1)<=x) {
        a++;
    }
    long long ret=3*a-3;
    ret++;
    if (x>=a*a+a) {
        ret++;
    }
    if (x>=a*a+2*a) {
        ret++;
    }
    return ret;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        long long l,r;
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",f(r)-f(l-1));
    }
    return 0;
}