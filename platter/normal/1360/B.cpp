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
        sort(arr,arr+n);
        int ret=1e5;
        for(int i=1;i<n;i++) {
            ret=min(ret,arr[i]-arr[i-1]);
        }
        printf("%d\n",ret);
    }
}