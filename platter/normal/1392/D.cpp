#include <bits/stdc++.h>
using namespace std;
 
int dp[200001];
char str[200000];
int arr[200000];
int n;
 
int ans(int ind) {
    if (ind==n) {
        return 0;
    }
    if (ind>n) {
        return 1e9;
    }
    if (dp[ind]!=-1) {
        return dp[ind];
    }
    int ret=1e9;
    if (ind<=n-2) {
        int val=(1^arr[ind])+arr[ind+1]+ans(ind+2);
        ret=min(ret,val);
    }
    if (ind<=n-3) {
        int val=(1^arr[ind])+arr[ind+1]+arr[ind+2]+ans(ind+3);
        ret=min(ret,val);
    }
    if (ind<=n-3) {
        int val=(1^arr[ind])+(1^arr[ind+1])+arr[ind+2]+ans(ind+3);
        ret=min(ret,val);
    }
    if (ind<=n-4) {
        int val=(1^arr[ind])+(1^arr[ind+1])+arr[ind+2]+arr[ind+3]+ans(ind+4);
        ret=min(ret,val);
    }
    dp[ind]=ret;
    return ret;
}
 
int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%c",&str[i]);
            if (str[i]=='L') {
                arr[i]=0;
            }
            else {
                arr[i]=1;
            }
        }
        scanf("\n");
        int ret=0;
        int st=0;
        int enval=0;
        if (arr[0]==arr[n-1]) {
            for(int i=n-1;i>=0;i--) {
                if (arr[i]!=arr[0]) {
                    break;
                }
                enval++;
            }
        }
        if (enval==n) {
            printf("%d\n",(n+2)/3);
            continue;
        }
        int row=enval+1;
        for(int i=1;i<n;i++) {
            if (arr[i-1]!=arr[i]) {
                ret+=row/3;
                row=1;
            }
            else {
                row++;
            }
        }
        if (arr[0]!=arr[n-1]) {
            ret+=row/3;
        }
        printf("%d\n",ret);
    }
}