#include <bits/stdc++.h>

using namespace std;
const int f=1000002;
long long n, a, b, c, d, t[f], e[f], k[f], dp[f], mini=1e18, es;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    for (int i=1; i<=n; i++) {
        dp[i]=mini;
        cin >> t[i];
        k[i]=a*t[i]+c;
        e[i]=min({a+b, t[i]*a+2*a, t[i]*a+c});
        es+=e[i];
    }
    for (int i=1; i<=n; i++) {
        mini=min(mini, dp[i-1]+es+min(k[n]-e[n], 2*d)+2*d*(n-i));
        es-=e[i];
        dp[i]=min(dp[i], dp[i-1]+k[i]+d);
        dp[i+1]=min(dp[i+1], dp[i-1]+e[i]+e[i+1]+4*d);
    }
    mini=min(mini, dp[n]-d);
    cout << mini << "\n";
    return 0;
}