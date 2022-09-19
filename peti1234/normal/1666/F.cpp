#include <bits/stdc++.h>

using namespace std;
const int c=5005;
long long w, n, cnt, dp[c][c], alatt[c][c], mod=998244353;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<c; i++) {
        for (int j=0; j<=i; j++) {
            alatt[i][j]=(j==0 ? 1 : (alatt[i-1][j]+alatt[i-1][j-1])%mod);
        }
    }
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            m[-x]++;
        }
        dp[0][0]=1;
        for (auto p:m) {
            int db=p.second;
            for (int kezd=0; kezd<=min(n/2, cnt); kezd++) {
                int s=cnt-kezd;
                dp[kezd][s]%=mod;
                if (!dp[kezd][s]) continue;
                for (int i=0; i<=1; i++) {
                    int hely=kezd-s-1+(kezd==0)+(kezd==n/2), t=db-i;
                    dp[kezd+i][s+db-i]+=dp[kezd][s]*alatt[hely][t]%mod;
                }
            }
            cnt+=db;
        }


        cout << dp[n/2][n/2]%mod << "\n";

        m.clear();
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                dp[i][j]=0;
            }
        }
        cnt=0;
    }
    return 0;
}
/*
1
2
1 2
*/
/*
1
8
1 1 2 3 4 4 6 7
*/