#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, sum, t[100002], dp[300002], mod=998244353, f;
ll oszt(ll a) {
    ll p=mod-2, ans=1;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i], sum+=t[i];
    dp[0]=n-1;
    for (int i=1; i<sum; i++) {
        ll pl=sum-i, mi=i*(n-1)%mod, ne=((n-1)*sum-pl-mi)%mod;
        mi*=oszt(pl), mi%=mod, ne*=oszt(pl), ne%=mod;
        dp[i]=(mi+mi*dp[i-1]+ne+1)%mod;
    }
    for (int i=sum-1; i>=0; i--) dp[i]+=dp[i+1], dp[i]%=mod;
    for (int i=1; i<=n; i++) f+=dp[t[i]];
    cout << (f-(n-1)*dp[0]+mod*mod)%mod*oszt(n)%mod;
    return 0;
}