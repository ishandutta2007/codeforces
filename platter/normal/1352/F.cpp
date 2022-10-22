#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n0,n1,n2;
        scanf("%d %d %d\n",&n0,&n1,&n2);
        if (n1==0) {
            if (n0>0) {
                for(int i=0;i<=n0+n1+n2;i++) {
                    printf("0");
                }
            }
            else {
                for(int i=0;i<=n0+n1+n2;i++) {
                    printf("1");
                }
            }
            printf("\n");
            continue;
        }
        int n=n0+n1+n2+1;
        for(int i=0;i<n0+1;i++) {
            printf("0");
        }
        for(int i=0;i<n2+1;i++) {
            printf("1");
        }
        for(int i=0;i<n-n0-n2-2;i++) {
            printf("%d",i%2);
        }
        printf("\n");
    }
}