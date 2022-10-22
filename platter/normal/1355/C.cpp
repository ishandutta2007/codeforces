#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main(void) {
    long long a,b,c,d;
    scanf("%lld %lld %lld %lld\n",&a,&b,&c,&d);
    long long ret=0;
    for(int i=a+b;i<=b+c;i++) {
        long long one=i-a;
        if (one>c) {
            one=c;
        }
        long long two=i-b;
        if (two<b) {
            two=b;
        }
        ret+=(one-two+1)*(i<=c?0LL:(min(i-c,d-c+1)));
    }
    printf("%lld",ret);
}