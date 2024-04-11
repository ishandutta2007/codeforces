#include <bits/stdc++.h>

using namespace std;
const int c=26, m=50000;
int t[2*c], n, dp[c*m][2*c], f, sum;
vector<int> a, b;
int main()
{
    cin >> n, f=(1<<n), dp[0][0]=1;
    n*=2;
    for (int i=1; i<=n; i++) cin >> t[i], sum+=t[i];
    sort(t+1, t+n+1), sum-=t[1]+t[2];
    a.push_back(t[1]), b.push_back(t[2]);
    for (int i=3; i<=n; i++) {
        for (int j=0; j<=sum/2; j++) {
            dp[j][i-2]=dp[j][i-3];
            if (j>=t[i] && dp[j-t[i]][i-3]) dp[j][i-2]=(dp[j][i-2]|(dp[j-t[i]][i-3]*2));
            dp[j][i-2]%=f;
        }
    }
    for (int j=sum/2; j>=0; j--) if (dp[j][n-2]>=f/2) {
        int x=j, y=f/2;
        for (int i=n; i>=3; i--) {
            if (y>1 && x>=t[i] && dp[x-t[i]][i-3]%y>=y/2) a.push_back(t[i]), x-=t[i], y/=2;
            else b.push_back(t[i]);
        }
        break;
    }
    sort(a.begin(), a.end()), sort(b.rbegin(), b.rend());
    for (int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << "\n";
    for (int i=0; i<b.size(); i++) cout << b[i] << " ";
    return 0;
}