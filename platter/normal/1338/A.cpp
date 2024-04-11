#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100005];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%lld ",&arr[i]);
        }
        long long maxi=arr[0];
        long long pm=-3e9;
        for(int i=0;i<n;i++) {
            maxi=max(maxi,arr[i]);
            pm=max(pm,maxi-arr[i]);
        }
        int cnt=0;
        long long val=1;
        while (pm>=val) {
            val*=2;
            cnt++;
        }
        printf("%d\n",cnt);
    }
}