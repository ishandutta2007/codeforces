#include <bits/stdc++.h>

using namespace std;
const int a=24, c=1<<a;
int n, dp[c], ans;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int ert=0;
        string s;
        cin >> s;
        for (auto c:s) {
            int k=c-'a';
            ert|=1<<k;
        }
        dp[ert]++;
    }
    for (int i=0; i<a; i++) {
        for (int mask=0; mask<c; mask++) {
            if ((mask & (1<<i))==0) {
                dp[mask+(1<<i)]+=dp[mask];
            }
        }
    }
    for (int i=0; i<c; i++) {
        dp[i]=n-dp[i];
        ans^=(dp[i]*dp[i]);
    }
    cout << ans << "\n";
    return 0;
}