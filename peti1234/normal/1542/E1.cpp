#include <bits/stdc++.h>

using namespace std;
const int c=505, k=c*c;
long long n, n2, ans, dp[k], kom[k], mod;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> mod;
    //n=6, mod=100000;
    n2=n*(n-1)/2;
    dp[0]=1;
    for (int i=0; i<=n2; i++) {
        kom[i]=1;
    }
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<=n2; j++) {
            dp[j]=kom[j];
            if (j>i) {
                dp[j]-=kom[j-i-1];
                dp[j]+=mod, dp[j]%=mod;
            }
        }
        kom[0]=dp[0];
        for (int j=1; j<=n2; j++) {
            kom[j]=(dp[j]+kom[j-1])%mod;
        }
/*
        cout << "ertekek " << i << "\n";
        for (int j=0; j<=n2; j++) {
            cout << dp[j] << " ";
        }
        cout << "\n";
        for (int j=0; j<=n2; j++) {
            cout << kom[j] << " ";
        }
        cout << "\n";
*/
        long long ert=1, db=n-i-2;
        for (int j=n; j>n-db; j--) {
            ert*=j;
            ert%=mod;
        }
        //cout << "vege " << i << " " << ert << "\n";

        for (int dif=1; dif<=i+1; dif++) {
            //cout << "proba " << n-i-1 << " " << dif << "\n";
            long long s=ert*(i+2-dif)%mod;
            //cout << "kezd " << s << "\n";
            long long sum=0;
            for (int nagy=dif+1; nagy<=n2; nagy++) {
                ans+=dp[nagy]*kom[nagy-dif-1]%mod*s%mod;
                ans%=mod;
                sum+=dp[nagy]*kom[nagy-dif-1];
            }
            //cout << "sum " << sum << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
4
10000
*/