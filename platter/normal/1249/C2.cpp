#include <cstdio>

int a[100];
int now=0;
long long n;

void make3(long long n) {
    while(n>0) {
        a[now]=n%3;
        n/=3;
        now+=1;
    }
}

long long p3(int n) {
    if (n==0)
    return 1;
    return p3(n-1)*3;
}

long long ans(long long n) {
    long long store=0;
    int index=now-1;
    for(int i=index;i>=0;i--) {
        if (a[i]==2) {
            for(int j=i+1;j<now;j++) {
                a[j]+=1;
                if (a[j]!=2) {
                    store+=p3(j);
                    return store;
                }
                store-=(a[j]-1)*p3(j);
            }
            return p3(now);
        }
        store+=a[i]*p3(i);
    }
    return store;
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        now=0;
        scanf("%lld\n", &n);
        for(int i=0;i<100;i++) {
            a[i]=0;
        }
        make3(n);
        printf("%lld\n", ans(n));
    }
    return 0;
}