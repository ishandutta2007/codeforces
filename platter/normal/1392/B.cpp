#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        long long k;
        scanf("%d %lld",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        if (k%2==1) {
            int maxi=-1e9;
            for(int i=0;i<n;i++) {
                maxi=max(maxi,arr[i]);
            }
            for(int i=0;i<n;i++) {
                printf("%d ",maxi-arr[i]);
            }
        }
        else {
            int mini=1e9;
            for(int i=0;i<n;i++) {
                mini=min(mini,arr[i]);
            }
            for(int i=0;i<n;i++) {
                printf("%d ",arr[i]-mini);
            }
        }
        printf("\n");
    }
}