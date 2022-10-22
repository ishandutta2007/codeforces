#include <bits/stdc++.h>
using namespace std;

char str[6];
int pow10[5]={1,10,100,1000,10000};

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        long long lo=0; //miman
        long long hi=1e10; //isang
        while (lo+1<hi) {
            long long mid=(lo+hi)/2;
            long long val=((mid/n)*(n-1))+mid%n;
            if (val>=k) {
                hi=mid;
            }
            else {
                lo=mid;
            }
        }
        printf("%lld\n",hi);
    }
}