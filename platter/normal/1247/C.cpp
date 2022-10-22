#include <cstdio>

int division(int n) {
    if (n==0)
    return 100000000;
    int ret=0;
    while(n>0) {
        ret+=n%2;
        n=n/2;
    }
    return ret;
}

int main(void) {
    int n,p;
    scanf("%d %d", &n, &p);
    int ans=0;
    while (1) {
        n-=p;
        if (ans>=100) {
            printf("-1");
            return 0;
        }
        if (n<0) {
            printf("-1");
            return 0;
        }
        ans+=1;
        if (division(n)<=ans&&ans<=n) {
            printf("%d",ans);
            return 0;
        }
    }
}