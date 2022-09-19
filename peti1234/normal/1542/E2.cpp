#include <bits/stdc++.h>

using namespace std;
const int c=505000, M=c/2;
long long n, n2, ans, mod, dp[c], kom[c];
int main()
{
    cin >> n >> mod;
    n2=n*(n-1)/2;
    dp[M]=1;
    for (int i=M; i<c; i++) {
        kom[i]=1;
    }
    for (int i=1; i<n; i++) {
        long long sum=0, s=M-n2, pr=1;
        for (int j=s-i; j<=s+i; j++) {
            sum+=dp[j]*(i-abs(i-j));
        }
        sum%=mod;
        for (int j=s; j<=M+n2; j++) {
            dp[j]=sum;
            sum+=kom[j+i]-2*kom[j]+kom[j-i]+2*mod;
            while (sum>=mod) {
                sum-=mod;
            }
        }
        for (int i=1; i<c; i++) {
            kom[i]=(kom[i-1]+dp[i]);
            if (kom[i]>=mod) {
                kom[i]-=mod;
            }
        }
        for (int j=i+2; j<=n; j++) {
            pr=pr*j%mod;
        }
        for (int dif=1; dif<=i; dif++) {
            ans+=kom[M-dif-1]*pr%mod*(i+1-dif)%mod;
            if (ans>=mod) {
                ans-=mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}