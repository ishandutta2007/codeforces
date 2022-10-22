#include <bits/stdc++.h>
using namespace std;

int arr[100];
int n;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int prev=-1;
        int en;
        for(int i=0;;i++) {
            int pos=-1;
            int maxi=0;
            for(int j=0;j<n;j++) {
                if (arr[j]>maxi&&j!=prev) {
                    pos=j;
                    maxi=arr[j];
                }
            }
            if (pos==-1) {
                en=i;
                break;
            }
            prev=pos;
            arr[pos]--;
        }
        printf("%s\n",(en%2==0?"HL":"T"));
    }
    return 0;
}