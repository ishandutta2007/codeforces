#include<bits/stdc++.h>
using namespace std;

int arr[50];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        if (sum==0) {
            printf("NO\n");
            continue;
        }
        sort(arr,arr+n);
        if (sum>0) {
            reverse(arr,arr+n);
        }
        printf("YES\n");
        for(int i=0;i<n;i++) {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}