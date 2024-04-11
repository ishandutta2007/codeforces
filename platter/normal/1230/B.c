#include <stdio.h>
 
int main() {
    int n,k;
    scanf("%d %d\n", &n, &k);
    int a[200000]={};
    for(int i=0;i<n;i++) {
        scanf("%1d", &a[i]);
    }
    int did=0;
    if (n==1) {
        if (k==1) {
            printf("0");
            return 0;
        }
        printf("%d", a[0]);
        return 0;
    }
    if (k!=0) {
        if (a[0]!=1) {
            did+=1;
            a[0]=1;
        }
    }
    int i=1;
    while(did<k) {
        if (a[i]!=0) {
            did+=1;
            a[i]=0;
        }
        i+=1;
        if (i==n) {
            break;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d", a[i]);
    }
    return 0;
}