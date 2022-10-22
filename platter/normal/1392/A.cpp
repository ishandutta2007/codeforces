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
        int prev=arr[0];
        bool flag=true;
        for(int i=1;i<n;i++) {
            if (arr[i]!=prev) {
                flag=false;
            }
        }
        printf("%d\n",flag?n:1);
    }
}