#include <bits/stdc++.h>
using namespace std;

int arr[200000];

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
        int ind=0;
        while (ind<n) {
            for(int i=ind;i<n;i++) {
                if (i-ind+1>=arr[i]) {
                    ret++;
                    ind=i+1;
                    break;
                }
                if (i==n-1) {
                    ind=n;
                    break;
                }
            }
        }
        printf("%d\n",ret);
    }
}