#include <bits/stdc++.h>
using namespace std;

bool dp[505][505];
int n,k;
long long a[505];
long long b[505];

int main(void) {
    scanf("%d %d\n",&n,&k);
    long long asum=0;
    long long bsum=0;
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld\n",&a[i],&b[i]);
        asum+=a[i];
        bsum+=b[i];
    }
    dp[0][0]=true;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<k;j++) {
            dp[i][j]=dp[i-1][(j-a[i]%k+k)%k];
            for(int l=0;l<=a[i]&&l<k;l++) {
                if ((a[i]-l)%k+b[i]>=k) {
                    dp[i][j]|=dp[i-1][(j-l+k)%k];
                }
            }
        }
    }
    long long ret=0;
    for(int i=0;i<k;i++) {
        if (dp[n][i]) {
            ret=max(ret,(asum+bsum-i)/k);
        }
    }
    printf("%lld",ret);
}