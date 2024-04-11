#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
int bit[100000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=29;j>=0;j--) {
            if (arr[i]&(1<<j)) {
                bit[i]=j;
                break;
            }
        }
    }
    for(int i=2;i<n;i++) {
        if (bit[i-2]==bit[i]&&bit[i-1]==bit[i]) {
            printf("1");
            return 0;
        }
    }
    int ret=1e6;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int lval=0;
            for(int k=i;k>=0;k--) {
                lval^=arr[k];
                int rval=0;
                for(int l=j;l<n;l++) {
                    rval^=arr[l];
                    if (lval>rval) {
                        ret=min(ret,i-k+l-j);
                    }
                }
            }
        }
    }
    printf("%d",ret>n?-1:ret);
}