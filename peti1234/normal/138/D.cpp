#include <bits/stdc++.h>

using namespace std;
const int c=42;
int n, m, t[c][c], dp[c][c][c][c][2];
bool v[c][c][c][c][2];
int solve(int kiso, int nagyo, int kisk, int nagyk, bool oe) {
    if (!v[kiso][nagyo][kisk][nagyk][oe]) {
        bool gr[200];
        for (int i=0; i<200; i++) {
            gr[i]=0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int sum=i+j, kul=i-j+m;
                if (sum%2==oe && kiso<sum && sum<nagyo && kisk<kul && kul<nagyk) {
                    int lep=0;
                    if (t[i][j]==1) {
                        lep=solve(kiso, sum, kisk, nagyk, oe)^solve(sum, nagyo, kisk, nagyk, oe);
                    }
                    if (t[i][j]==2) {
                        lep=solve(kiso, nagyo, kisk, kul, oe)^solve(kiso, nagyo, kul, nagyk, oe);
                    }
                    if (t[i][j]==3) {
                        lep=solve(kiso, sum, kisk, kul, oe)^solve(kiso, sum, kul, nagyk, oe)^solve(sum, nagyo, kisk, kul, oe)^solve(sum, nagyo, kul, nagyk, oe);
                    }
                    gr[lep]=1;
                }
            }
        }
        int ans=0;
        while (gr[ans]) {
            ans++;
        }
        v[kiso][nagyo][kisk][nagyk][oe]=1;
        dp[kiso][nagyo][kisk][nagyk][oe]=ans;
    }

    return dp[kiso][nagyo][kisk][nagyk][oe];
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='L') {
                t[i][j]=1;
            }
            if (c=='R') {
                t[i][j]=2;
            }
            if (c=='X') {
                t[i][j]=3;
            }
        }
    }
    int a=solve(1, n+m+1, 0, n+m, 0), b=solve(1, n+m+1, 0, n+m, 1);
    cout << (a==b ? "LOSE" : "WIN") << "\n";
    return 0;
}