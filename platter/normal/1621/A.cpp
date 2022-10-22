#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d",&n,&k);
        if (2*k-1<=n) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if (i==j&&i<2*k&&i%2==0) {
                        printf("R");
                    }
                    else {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}