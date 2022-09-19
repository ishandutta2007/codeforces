#include <bits/stdc++.h>

using namespace std;
const int c=5000005;
int w, n;
long long dp[c], db[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (int i=1; i<c; i++) for (int j=2*i; j<c; j+=i) db[i]+=db[j];
    for (int i=c-5; i>=1; i--) {
        dp[i]+=db[i]*i;
        for (int j=2*i; j<c; j+=i) dp[i]=max(dp[i], dp[j]+(db[i]-db[j])*i);
        maxi=max(maxi, dp[i]);
    }
    cout << maxi << "\n";
    return 0;
}