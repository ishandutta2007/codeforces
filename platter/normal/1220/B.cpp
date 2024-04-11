#include <stdio.h>
#include <math.h>

long long intsqr(long long n) {
    double nd=n;
    double y=sqrt(nd);
    long long k=y;
    if (k*k==n)
    return k;
    k--;
    if (k*k==n)
    return k;
    k++;
    k++;
    if (k*k==n)
    return k;
}

int main(void) {
    int n;
    scanf("%d\n", &n);
    long long a[1000][1000];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%lld ", &a[i][j]);
        }
        scanf("\n");
    }
    long long real[1000];
    for(int i=0;i<n;i++) {
        long long x=1;
        x*=a[i][(i+1)%n];
        x*=a[(i+2)%n][(i+1)%n];
        x/=a[i][(i+2)%n];
        x=intsqr(x);
        real[(i+1)%n]=x;
    }
    for(int i=0;i<n;i++) {
        printf("%lld ", real[i]);
    }
    return 0;
}