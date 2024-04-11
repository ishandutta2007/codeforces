#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int prev=-2;
        int ret=0;
        for(int i=0;i<n;i++) {
            if (prev<arr[i]) {
                prev=arr[i];
                ret++;
            }
            else if (prev==arr[i]) {
                prev=arr[i]+1;
                ret++;
            }
        }
        printf("%d\n",ret);
    }
}