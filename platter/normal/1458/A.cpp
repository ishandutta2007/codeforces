#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

long long arr[200000];

int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }
    long long ret=0;
    for(int i=1;i<n;i++) {
        ret=gcd(ret,arr[i]-arr[i-1]>0?arr[i]-arr[i-1]:arr[i-1]-arr[i]);
    }
    for(int i=0;i<m;i++) {
        long long x;
        scanf("%lld",&x);
        printf("%lld ",gcd(ret,x+arr[0]));
    }
}