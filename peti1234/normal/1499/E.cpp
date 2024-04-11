#include <bits/stdc++.h>

using namespace std;
const int c=1002;
long long n, m, dp[c][c][2], sum=0, mod=998244353;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    n=a.size(), m=b.size();
    a+='_', b+='_';
    for (int i=n-1; i>=0; i--) {
        if (a[i]!=a[i+1]) {
            dp[i][m][0]=dp[i+1][m][0];
        }
        dp[i][m][0]++;
    }
    for (int j=m-1; j>=0; j--) {
        if (b[j]!=b[j+1]) {
            dp[n][j][1]+=dp[n][j+1][1];
        }
        dp[n][j][1]++;
    }
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            long long x=0, y=0;
            if (a[i]!=b[j]) {
                x+=dp[i+1][j][1];
                if (i!=n-1) x+=dp[n][j][1];
                y+=dp[i][j+1][0];
                if (j!=m-1) y+=dp[i][m][0];
            }
            if (a[i]!=a[i+1] && i!=n-1) {
                x+=dp[i+1][j][0];
            }
            if (b[j]!=b[j+1] && j!=m-1) {
                y+=dp[i][j+1][1];
            }
            x%=mod, y%=mod;
            sum+=x+y, sum%=mod;
            dp[i][j][0]=x, dp[i][j][1]=y;
        }
    }
    cout << sum << "\n";
    return 0;
}