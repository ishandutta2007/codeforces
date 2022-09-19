#include <bits/stdc++.h>

using namespace std;
long long n, dp[100002][11], ans, k=11;
string s;
int main()
{
    cin >> s, n=s.size();
    for (int i=1; i<=n; i++) {
        int x=s[i-1]-'0';
        for (int j=x+1; j<k; j++) {
            dp[i][(j*(j-1)/2+10+x)%k]+=dp[i-1][j];
        }
        if (x) {
            dp[i][x]++;
        }
        for (int j=0; j<k; j++) {
            ans+=dp[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}