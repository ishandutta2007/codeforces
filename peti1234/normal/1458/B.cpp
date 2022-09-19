#include <bits/stdc++.h>

using namespace std;
const int c=102, s=20002;
int n, x, y, sum, dp[c][s], maxi[c];
bool v[c][s];
int main()
{
    v[0][0]=1;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x >> y, sum+=y;
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<s; j++) {
                if (v[i][j]) {
                    v[i+1][j+y]=1;
                    dp[i+1][j+y]=max(dp[i+1][j+y], dp[i][j]+x);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<s; j++) {
            maxi[i]=max(maxi[i], min(2*dp[i][j], sum+j));
        }
    }
    for (int i=1; i<=n; i++) {
        cout << double(maxi[i])/2 << " ";
    }
    return 0;
}