#include <bits/stdc++.h>
using namespace std;
 
char str[6];
int pow10[5]={1,10,100,1000,10000};
int arr[1000];
 
int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        int l=0;
        int r=n-1;
        int ret=0;
        int a=0;
        int b=0;
        int prev=0;
        while (1) {
            ret++;
            int ate=0;
            while (ate<=prev&&l<=r) {
                ate+=arr[l];
                l++;
            }
            prev=ate;
            a+=ate;
            if (l>r) {
                break;
            }
            ate=0;
            ret++;
            while (ate<=prev&&l<=r) {
                ate+=arr[r];
                r--;
            }
            prev=ate;
            b+=ate;
            if (l>r) {
                break;
            }
        }
        printf("%d %d %d\n",ret,a,b);
    }
}