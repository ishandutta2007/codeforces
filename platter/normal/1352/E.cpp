#include <bits/stdc++.h>
using namespace std;
 
char str[6];
int pow10[5]={1,10,100,1000,10000};
int arr[8000];
 
int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%d ",&arr[i]);
        }
        int ret=0;
        for(int i=0;i<n;i++) {
            int r=-1;
            int sum=0;
            bool flag=false;
            for(int j=0;j<n;j++) {
                while (sum<arr[i]&&r<n-1) {
                    sum+=arr[++r];
                }
                if (j<r&&sum==arr[i]) {
                    flag=true;
                    break;
                }
                sum-=arr[j];
            }
            ret+=flag;
        }
        printf("%d\n",ret);
    }
}