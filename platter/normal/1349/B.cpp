#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
long long arr[100005];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %lld\n",&n,&k);
        bool flag=false;
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
            if (arr[i]==k) {
                flag=true;
            }
        }
        if (!flag) {
            printf("no\n");
            continue;
        }
        if (n==1) {
            printf("yes\n");
            continue;
        }
        int prev=-5;
        flag=false;
        for(int i=0;i<n;i++) {
            if (arr[i]>=k) {
                if (i-prev<3) {
                    flag=true;
                    break;
                }
                prev=i;
            }
        }
        printf("%s\n",flag?"yes":"no");
    }
}