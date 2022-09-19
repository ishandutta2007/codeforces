#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, t[c], dp[c], pref[c], st[c], dp2[c], sum, pos, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    dp[0]=1, pref[0]=mod-1;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        while (pos>0 && t[i]<t[st[pos]]) {
            pos--;
        }
        if (!pos) {
            dp[i]=pref[i-1]*t[i]%mod;
        } else {
            dp[i]=(dp2[st[pos]]+(pref[i-1]-pref[st[pos]-1]+mod)*t[i])%mod;
        }
        st[++pos]=i;
        dp2[i]=dp[i];
        if (i%2) {
            dp[i]=mod-dp[i];
        }
        pref[i]=(mod+pref[i-1]-dp2[i])%mod;
    }
    cout << dp[n]%mod << "\n";
    return 0;
}