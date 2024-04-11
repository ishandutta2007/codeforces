#include <bits/stdc++.h>

using namespace std;
const int c=200002, p=20;
int n, m, q, cnt[c], dp[c][p];
bool db[c][p];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i=1; i<=m; i++) {
        db[i][0]=(cnt[i]%2);
    }
    for (int j=1; j<p; j++) {
        for (int i=1; i+(1<<j)<=m+1; i++) {
            int k=1<<(j-1), s=i+k;
            dp[i][j]=dp[i][j-1]^dp[s][j-1];
            if (db[s][j-1]) {
                dp[i][j]^=k;
            }
            db[i][j]=(db[i][j-1]^db[s][j-1]);
        }
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        r++;
        int sum=0;
        bool sz=0;
        for (int i=0; i<p; i++) {
            int s=(1<<i);
            if ((r-l) & s) {
                r-=s;
                sum=sum^dp[r][i];
                if (sz) {
                    sum^=s;
                }
                sz=sz^db[r][i];
            }
        }
        cout << (sum ? "A" : "B");
    }
    return 0;
}