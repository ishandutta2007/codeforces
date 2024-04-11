#include <bits/stdc++.h>

using namespace std;
const int c=505;
int n, m, a[c], b[c], el[c][c], dp[c][c], lep[c][c], ans, aa, bb;
vector<int> p;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        int ut=0;
        for (int j=1; j<=m; j++) {
            if (a[i]==b[j]) {
                ut=j;
            }
            el[j][i]=ut;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i]!=b[j]) continue;
            dp[i][j]=1;
            for (int k=1; k<i; k++) {
                if (a[i]==a[k]) {
                    dp[i][j]=max(dp[i][j], dp[k][j]);
                }
                if (a[k]<a[i] && dp[k][el[j][k]]+1>dp[i][j]) {
                    dp[i][j]=dp[k][el[j][k]]+1;
                    lep[i][j]=k;
                }
            }
            if (dp[i][j]>ans) {
                ans=dp[i][j];
                aa=i, bb=j;
            }
        }
    }
    cout << ans << "\n";
    while (aa || bb) {
        p.push_back(a[aa]);
        int s=lep[aa][bb];
        aa=s, bb=el[bb][s];
    }
    reverse(p.begin(), p.end());
    for (auto x:p) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}