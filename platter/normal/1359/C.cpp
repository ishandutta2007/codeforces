#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int T=0;T<tc;T++) {
        long long h,c,t;
        scanf("%lld %lld %lld\n",&h,&c,&t);
        if (2*t<=h+c) {
            printf("2\n");
            continue;
        }
        long long lo=0; //temp_now>=t
        long long hi=1e6; //temp_now<t
        while (lo+1<hi) {
            long long mid=(lo+hi)/2;
            if ((2*mid+1)*c+(mid+1)*(h-c)>=t*(2*mid+1)) {
                lo=mid;
            }
            else {
                hi=mid;
            }
        }
        if ((4*lo*lo+10*lo+5)*(h-c)<=2*(t-c)*(4*lo*lo+8*lo+3)) {
            printf("%lld\n",2*lo+1);
        }
        else {
            printf("%lld\n",2*lo+3);
        }
    }
}