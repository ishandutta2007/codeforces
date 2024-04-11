#include <cstdio>

int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

int main(void) {
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<n;i++) {
        int r,b,k;
        scanf("%d %d %d\n", &r, &b, &k);
        if (r<b) {
            int temp=r;
            r=b;
            b=temp;
        }
        int divide=gcd(r,b);
        r/=divide;
        b/=divide;
        if ((r-2)/b>=k-1) {
            printf("REBEL\n");
        }
        else {
            printf("OBEY\n");
        }
    }
    return 0;
}