#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[500000];
long long x;
long long ssum[500000];

int main(void) {
    scanf("%d\n",&n);
    int half=(n-1)/2+1;
    for(int i=0;i<half;i++) {
        scanf("%lld",&arr[i]);
    }
    scanf("%lld",&x);
    if (x>=0) {
        long long sum=0;
        for(int i=0;i<half;i++) {
            sum+=arr[i];
        }
        printf("%d",sum+(n-half)*x>0?n:-1);
        return 0;
    }
    else {
        int upper=n;
        ssum[half]=0;
        for(int i=half-1;i>=0;i--) {
            ssum[i]=ssum[i+1]+arr[i];
        }
        for(int i=0;i<half;i++) {
            if (ssum[i]<=0) {
                printf("-1");
                return 0;
            }
            upper=min((long long)upper,half-i+(ssum[i]-1)/(-x));
            if (n-i<=upper) {
                printf("%d",upper);
                return 0;
            }
        }
        printf("-1");
        return 0;
    }
}