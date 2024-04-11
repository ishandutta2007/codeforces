#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        long long ret=0;
        for(int i=1;i<n;i++) {
            ret+=max(arr[i-1]-arr[i],0);
        }
        printf("%lld\n",ret);
    }
}