#include <bits/stdc++.h>
using namespace std;

long long arr[100][100];
long long dp[100][100];
const long long INF=1e18;

int n,m;

bool valid(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<m;
}

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d\n",&n,&m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%lld ",&arr[i][j]);
                arr[i][j]-=i+j;
            }
            scanf("\n");
        }
        long long ret=INF;
        for(int one=0;one<n;one++) {
            for(int two=0;two<m;two++) {
                long long val=arr[one][two];
                if (arr[0][0]<val) {
                    continue;
                }
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        dp[i][j]=INF;
                    }
                }
                dp[0][0]=arr[0][0]-val;
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        if (arr[i][j]>=val) {
                            if (valid(i-1,j)) {
                                dp[i][j]=min(dp[i][j],dp[i-1][j]+arr[i][j]-val);
                            }
                            if (valid(i,j-1)) {
                                dp[i][j]=min(dp[i][j],dp[i][j-1]+arr[i][j]-val);
                            }
                        }
                    }
                }
                ret=min(ret,dp[n-1][m-1]);
            }
        }
        printf("%lld\n",ret);
    }
}