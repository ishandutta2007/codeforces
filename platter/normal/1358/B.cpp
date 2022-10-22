#include <bits/stdc++.h>
using namespace std;

int arr[100000];

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
        int ret=0;
        for(int i=0;i<n;i++) {
            if (arr[i]<=i+1) {
                ret=i+1;
            }
        }
        printf("%d\n",ret+1);
    }
}