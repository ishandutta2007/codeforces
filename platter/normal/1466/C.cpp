#include <bits/stdc++.h>
using namespace std;

char str[100001];
int dp[100001];

int ans(int ind) {
    if (ind<=0) {
        return 0;
    }
    if (dp[ind]!=-1) {
        return dp[ind];
    }
    if (ind==1) {
        return str[0]==str[1];
    }
    if (str[ind-2]!=str[ind]&&str[ind-1]!=str[ind]) {
        return dp[ind]=ans(ind-1);
    }
    if (str[ind-2]==str[ind]&&str[ind-1]!=str[ind]) {
        if (ind>=3&&str[ind-3]==str[ind-1]) {
            return dp[ind]=ans(ind-4)+2;
        }
        else {
            return dp[ind]=ans(ind-3)+1;
        }
    }
    if (str[ind-2]!=str[ind]&&str[ind-1]==str[ind]) {
        return dp[ind]=ans(ind-2)+1;
    }
    return dp[ind]=ans(ind-3)+2;
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<n;i++) {
            dp[i]=-1;
        }
        printf("%d\n",ans(n-1));
    }
}