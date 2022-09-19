#include <bits/stdc++.h>

using namespace std;
const long long c=100002;
long long w, n, p, k, x, y, dp[c], f, mini;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> p >> k >> s >> x >> y, mini=2e9;
        for (int i=n; i>=1; i--) {
            int f=(s[i-1]=='0');
            if (i+k>n) dp[i]=f*x;
            else dp[i]=f*x+dp[i+k];
        }
        for (int i=p; i<=n; i++) {
            mini=min(mini, dp[i]+(i-p)*y);
        }
        cout << mini << "\n";
    }
    return 0;
}