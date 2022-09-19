#include <bits/stdc++.h>
 
using namespace std;
int n;
long long t[300001], dp[21];
int ans(int a, int b)
{
    int db=0;
    while(a<b) {
        a*=2;
        db++;
    }
    return db;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=18; i++) {
        dp[i]=1e12;
    }
    for (int i=n; i>=1; i--) {
        int x=ans(i, n);
        if (t[i]==-1) {
            cout << dp[x] << "\n";
            return 0;
        }
        for (int j=18; j>=x+1; j--) {
            dp[j]=min(dp[j], dp[j-1]+t[i]);
        }
    }
    return 0;
}