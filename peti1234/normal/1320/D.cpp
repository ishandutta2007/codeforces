#include<bits/stdc++.h>

using namespace std;
const int c=200002, mod=998244353, base=3;
long long n, q, x, y, h, dp[c][2], cnt[c], po[c];
string s;
long long ask(int x, int h) {
    x--;
    bool s=(x%2);
    return (dp[x+h][s]-dp[x][s]*po[cnt[x+h]-cnt[x]]%mod+mod)%mod;
}
int main()
{
    po[0]=1;
    cin >> n;
    cin >> s;
    for (int i=1; i<=n; i++) {
        bool k=(s[i-1]=='0'), p=i%2;
        cnt[i]=cnt[i-1]+k;
        po[i]=po[i-1]*base%mod;
        dp[i][0]=dp[i-1][0], dp[i][1]=dp[i-1][1];
        if (k) {
            dp[i][0]=((dp[i][0]*base)+1+p)%mod;
            dp[i][1]=((dp[i][1]*base)+2-p)%mod;
        }
    }
    cin >> q;
    while (q--) {
        cin >> x >> y >> h;
        cout << (ask(x, h)==ask(y, h) ? "Yes" : "No") << "\n";
    }
    return 0;
}