#include <bits/stdc++.h>
using namespace std;

int arr[30000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",arr+i);
        }
        long long sum=0;
        for(int i=1;i<n;i++) {
            sum+=max(arr[i-1]-arr[i],0);
        }
        printf("%s\n",sum<=arr[0]?"YES":"NO");
    }
}