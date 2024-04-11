#include <bits/stdc++.h>

using namespace std;
const int k=20, c=(1<<20);
int n, m, dp[c], db[k][k], t[c];
string s;
int lsb(int a) {
    return (a&(-a));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> s;
    for (int i=0; i<m-1; i++) {
        int x=s[i]-'a', y=s[i+1]-'a';
        db[x][y]++, db[y][x]++;
    }
    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (i&(1<<j) && !(i&(1<<k))) {
                    t[i]+=db[j][k];
                }
            }
        }
    }
    for (int i=1; i<(1<<n); i++) {
        dp[i]=1e7;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                dp[i]=min(dp[i], dp[i-(1<<j)]+t[i]);
            }
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}