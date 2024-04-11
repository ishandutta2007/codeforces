#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, dp[c][c], sa, sb;
vector<int> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    sa=a.size(), sb=b.size();
    for (int i=1; i<=sa; i++) {
        for (int j=0; j<=sb; j++) {
            dp[i][j]=1e9;
        }
    }
    for (int i=1; i<=sa; i++) {
        for (int j=1; j<=sb; j++) {
            dp[i][j]=min(dp[i][j-1], dp[i-1][j-1]+abs(a[i-1]-b[j-1]));
        }
    }
    cout << dp[sa][sb] << "\n";
    return 0;
}