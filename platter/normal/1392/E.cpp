#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d",&n);
    for(int x=0;x<n;x++) {
        for(int y=0;y<n;y++) {
            int val=x+y;
            long long val2=y%2;
            printf("%lld ",val2<<val);
        }
        printf("\n");
        fflush(stdout);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++) {
        long long k;
        scanf("%lld",&k);
        int x=0;
        int y=0;
        printf("1 1\n");
        fflush(stdout);
        for(int i=1;i<2*n-1;i++) {
            if (((k>>i)&1)^((k>>(i-1))&1)) {
                y++;
            }
            else {
                x++;
            }
            printf("%d %d\n",x+1,y+1);
            fflush(stdout);
        }
    }
}