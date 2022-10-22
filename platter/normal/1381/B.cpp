#include <bits/stdc++.h>
using namespace std;

int arr[4000];
bool dp[4001][4001];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<2*n;i++) {
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<=2*n;i++) {
            for(int j=0;j<=2*n;j++) {
                dp[i][j]=false;
            }
        }
        int now=0;
        vector<int> v;
        v.push_back(0);
        while (now<2*n) {
            int i;
            for(i=now;i<2*n&&arr[i]<=arr[now];i++);
            v.push_back(i-now);
            now=i;
        }
        dp[0][0]=true;
        for(int i=1;i<v.size();i++) {
            for(int j=0;j<=2*n;j++) {
                dp[i][j]=dp[i-1][j];
                if (j>=v[i]) {
                    dp[i][j]|=dp[i-1][j-v[i]];
                }
            }
        }
        printf("%s\n",dp[v.size()-1][n]?"YES":"NO");
    }
}