#include <bits/stdc++.h>

using namespace std;
const int c=20, c2=1<<c;
long long t[c][c], db[c], dp[c2], n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        x--;
        for (int i=0; i<c; i++) {
            t[x][i]+=db[i];
        }
        db[x]++;
    }
    for (int i=0; i<c; i++) {
        t[i][i]=0;
    }
    for (int mask=1; mask<c2; mask++) {
        dp[mask]=1e12;
        for (int i=0; i<c; i++) {
            if (mask & (1<<i)) {
                long long ert=dp[mask-(1<<i)];
                for (int j=0; j<c; j++) {
                    if (mask & (1<<j)) {
                        ert+=t[j][i];
                    }
                }
                dp[mask]=min(dp[mask], ert);
            }
        }
    }
    cout << dp[c2-1] << "\n";

    return 0;
}
/*
3
1 2 1
*/