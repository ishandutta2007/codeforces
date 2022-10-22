#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int arr2[200000];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            arr2[i]=arr[i];
        }
        sort(arr2,arr2+n);
        int len=n-(n-k)/2;
        int ret=1e9;
        int st=0;
        for(int i=0;i<=n-len;i++) {
            if (arr2[i+len-1]-arr2[i]<ret) {
                st=arr2[i];
                ret=arr2[i+len-1]-arr2[i];
            }
        }
        printf("%d %d\n",st,st+ret);
        int pr=0;
        int cnt=0;
        int left=k;
        for(int i=0;i<n;i++) {
            if (arr[i]<st||arr[i]>st+ret) {
                cnt++;
            }
            if (left>1&&cnt<(i-pr+2)/2) {
                printf("%d %d\n",pr+1,i+1);
                left--;
                cnt=0;
                pr=i+1;
            }
        }
        printf("%d %d\n",pr+1,n);
    }
}