#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, dp[c], t[c];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (int i=1; i<=n; i++) {
        t[i]=(s[i-1]-'0');
        dp[i]=dp[i-1];
        int sum=0;
        for (int j=1; j<=min(4, i); j++) {
            sum+=t[i-j+1];
            if (sum%3==0) {
                dp[i]=max(dp[i], dp[i-j]+1);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}