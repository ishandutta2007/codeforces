#include <bits/stdc++.h>

using namespace std;
const int c=40005;
vector<int> pal;
long long dp[c], mod=1e9+7;
void add(int x) {
    for (int i=0; i+x<c; i++) {
        dp[i+x]=(dp[i+x]+dp[i])%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    dp[0]=1;
    for (int i=1; i<=1000; i++) {
        int ert=i, s=i;
        while (s) {
            ert*=10;
            ert+=s%10;
            s/=10;
        }
        add(ert);
        ert=i, s=i/10;
        while (s) {
            ert*=10;
            ert+=s%10;
            s/=10;
        }
        add(ert);
    }

    int w;
    cin >> w;
    while (w--) {
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }
    return 0;
}