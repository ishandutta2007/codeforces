#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, t[c], dp[c], pref[c], sum, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b, s;
        cin >> a >> b >> s;
        t[i]=a;
        int lo=0, hi=i, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (t[mid]<b) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        dp[i]=(pref[i-1]-pref[lo]+a-b+mod)%mod;
        pref[i]=(pref[i-1]+dp[i])%mod;
        if (s) {
            sum+=dp[i];
            sum%=mod;
        }
    }
    cout << (sum+t[n]+1)%mod << "\n";
    return 0;
}