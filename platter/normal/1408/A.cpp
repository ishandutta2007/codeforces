#include <bits/stdc++.h>
using namespace std;

int a[100];
int b[100];
int c[100];
int ret[100];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&c[i]);
        }
        ret[0]=a[0];
        for(int i=1;i<n-1;i++) {
            if (ret[i-1]==a[i]) {
                ret[i]=b[i];
            }
            else {
                ret[i]=a[i];
            }
        }
        int i=n-1;
        if (a[i]!=ret[0]&&a[i]!=ret[n-2]) {
            ret[n-1]=a[i];
        }
        if (b[i]!=ret[0]&&b[i]!=ret[n-2]) {
            ret[n-1]=b[i];
        }
        if (c[i]!=ret[0]&&c[i]!=ret[n-2]) {
            ret[n-1]=c[i];
        }
        for(int i=0;i<n;i++) {
            printf("%d ",ret[i]);
        }
        printf("\n");
    }
}