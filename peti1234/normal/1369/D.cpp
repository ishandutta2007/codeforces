#include <bits/stdc++.h>

using namespace std;
const int c=2000002;
int w, n;
long long dp[c], mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    dp[1]=1;
    for (int i=2; i<c; i++) dp[i]=(2*dp[i-2]+dp[i-1])%mod;
    for (int i=4; i<c; i++) dp[i]+=dp[i-3], dp[i]%=mod;
    cin >> w;
    while(w--) {
        cin >> n;
        cout << (4*dp[n-2])%mod << "\n";
    }
    return 0;
}