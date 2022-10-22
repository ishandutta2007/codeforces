#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[100][100][101][3];
int arr[100];
int n;

int ans(int odd,int even,int ind,int type) {
    if (dp[odd][even][ind][type]!=-1) {
        return dp[odd][even][ind][type];
    }
    if (ind==n) {
        return 0;
    }
    int ret=0;
    if (type==2) {
        if (arr[ind]!=-1) {
            if (arr[ind]==0) {
                ret=ans(odd,even,1,0);
            }
            else {
                ret=ans(odd,even,1,1);
            }
        }
        else {
            if (odd>0&&even>0)
            ret=min(ans(odd,even-1,1,0),ans(odd-1,even,1,1));
            else if (odd>0)
            ret=ans(odd-1,even,1,1);
            else
            ret=ans(odd,even-1,1,0);
        }
    }
    else if (type==0) {
        if (arr[ind]!=-1) {
            if (arr[ind]==0) {
                ret=ans(odd,even,ind+1,0);
            }
            else {
                ret=ans(odd,even,ind+1,1)+1;
            }
        }
        else {
            if (odd>0&&even>0)
            ret=min(ans(odd,even-1,ind+1,0),ans(odd-1,even,ind+1,1)+1);
            else if (odd>0)
            ret=ans(odd-1,even,ind+1,1)+1;
            else
            ret=ans(odd,even-1,ind+1,0);
        }
    }
    else {
        if (arr[ind]!=-1) {
            if (arr[ind]==0) {
                ret=ans(odd,even,ind+1,0)+1;
            }
            else {
                ret=ans(odd,even,ind+1,1);
            }
        }
        else {
            if (odd>0&&even>0)
            ret=min(ans(odd,even-1,ind+1,0)+1,ans(odd-1,even,ind+1,1));
            else if (odd>0)
            ret=ans(odd-1,even,ind+1,1);
            else
            ret=ans(odd,even-1,ind+1,0)+1;
        }
    }
    dp[odd][even][ind][type]=ret;
    return ret;
}

int main(void) {
    memset(dp,-1,sizeof(dp));
    scanf("%d\n",&n);
    int oddcnt=(n+1)/2;
    int evencnt=n/2;
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d ",&x);
        if (x==0) {
            arr[i]=-1;
        }
        else {
            arr[i]=x%2;
            if (arr[i]==0) {
                evencnt--;
            }
            else {
                oddcnt--;
            }
        }
    }
    printf("%d",ans(oddcnt,evencnt,0,2));
    return 0;
}