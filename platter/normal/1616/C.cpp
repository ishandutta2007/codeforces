#include <bits/stdc++.h>
using namespace std;

int arr[70];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        if (n<=2) {
            printf("0\n");
            continue;
        }
        int ret=1e9;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int val=0;
                for(int k=0;k<n;k++) {
                    if (arr[i]*(j-i)+(arr[j]-arr[i])*(k-i)!=arr[k]*(j-i)) {
                        val++;
                    }
                }
                ret=min(ret,val);
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}