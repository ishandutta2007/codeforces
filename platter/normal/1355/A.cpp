#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        long long a,k;
        scanf("%lld %lld\n",&a,&k);
        for(int i=1;i<min(1000LL,k);i++) {
            int mini=10;
            int maxi=0;
            long long val=a;
            while (val!=0) {
                mini=min((long long)mini,val%10);
                maxi=max((long long)maxi,val%10);
                val/=10;
            }
            a+=mini*maxi;
        }
        printf("%lld\n",a);
    }
}