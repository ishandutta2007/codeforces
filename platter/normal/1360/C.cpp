#include <bits/stdc++.h>
using namespace std;

int arr[50];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int even=0;
        int odd=0;
        for(int i=0;i<n;i++) {
            if (arr[i]%2==0) {
                even++;
            }
            else {
                odd++;
            }
        }
        if (even%2==0) {
            printf("YES\n");
            continue;
        }
        sort(arr,arr+n);
        bool flag=false;
        for(int i=1;i<n;i++) {
            if (arr[i]-arr[i-1]==1) {
                printf("YES\n");
                flag=true;
                break;
            }
        }
        if (!flag) {
            printf("NO\n");
        }
    }
}