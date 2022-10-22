#include <bits/stdc++.h>
using namespace std;

long long calinv(long long x) {
    long long lo=0;
    long long hi=2e9;
    while (lo+1<hi) {
        long long mid=(lo+hi)/2;
        if (mid*(mid-1)<x*2) {
            lo=mid;
        }
        else {
            hi=mid;
        }
    }
    if (hi*(hi-1)==x*2) {
        return hi;
    }
    else {
        return -1;
    }
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        long long lo=2; //j>lo
        long long hi=n-1; //j<=hi
        long long igot=-1;
        long long whole;
        printf("? 1 %d\n",n);
        fflush(stdout);
        scanf("%lld",&whole);
        long long ret=-1;
        int cnt=0;
        while (lo+1<hi) {
            //printf("%lld %lld\n",lo,hi);
            long long mid=(lo+hi)/2;
            printf("? 1 %lld\n",mid);
            fflush(stdout);
            long long got;
            scanf("%lld",&got);
            if (got==0) {
                lo=mid;
                continue;
            }
            if (got==whole) {
                hi=mid;
                continue;
            }
            long long val=calinv(got);
            //printf("%lld\n",val);
            if (val==-1) {
                hi=mid;
            }
            else {
                if (igot!=-1) {
                    if (val==mid-igot+1) {
                        lo=mid;
                    }
                    else {
                        hi=mid;
                    }
                }
                else {
                    long long got2;
                    printf("? 1 %lld\n",mid-1);
                    fflush(stdout);
                    scanf("%lld",&got2);
                    if (got-got2==val-1) {
                        igot=mid-val+1;
                        lo=mid;
                    }
                    else {
                        ret=mid-(got-got2);
                        break;
                    }
                }
            }
        }
        if (ret==-1) {
            ret=hi;
        }
        long long lgotb,lgots;
        printf("? 1 %lld\n",ret-1);
        fflush(stdout);
        scanf("%lld",&lgotb);
        printf("? 1 %lld\n",ret-2);
        fflush(stdout);
        scanf("%lld",&lgots);
        long long reti=ret-1-(lgotb-lgots);
        long long rgotb,rgots;
        printf("? %lld %d\n",ret,n);
        fflush(stdout);
        scanf("%lld",&rgotb);
        printf("? %lld %d\n",ret+1,n);
        fflush(stdout);
        scanf("%lld",&rgots);
        long long retk=ret+(rgotb-rgots);
        printf("! %lld %lld %lld\n",reti,ret,retk);
        fflush(stdout);
    }
    return 0;
}