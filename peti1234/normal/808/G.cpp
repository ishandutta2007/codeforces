#include <bits/stdc++.h>

using namespace std;
string a, b;
int n, m;
vector<vector<int> > dp;
vector<int> pi, kov;
int main()
{
    cin >> a >> b;
    n=a.size(), m=b.size();
    dp.resize(n+1);
    for (int i=0; i<n+1; i++) {
        dp[i].resize(m+1, -1e9);
    }
    pi.resize(m), kov.resize(m);
    for (int i=1; i<m; i++) {
        int h=pi[i-1];
        while (h>0 && b[i]!=b[h]) {
            h=pi[h-1];
        }
        if (b[i]==b[h]) {
            h++;
        }
        pi[i]=h;
    }
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        char c=a[i-1];
        kov[0]=0;
        for (int j=0; j<m; j++) {
            if (c=='?' || c==b[j]) {
                kov[j]=j+1;
            } else if (j) {
                kov[j]=kov[pi[j-1]];
            }
            dp[i][kov[j]]=max(dp[i][kov[j]], dp[i-1][j]);
            if (kov[j]==m) {
                dp[i][pi[m-1]]=max(dp[i][pi[m-1]], dp[i][m]+1);
            }
        }
        for (int j=m-1; j>=1; j--) {
            dp[i][pi[j-1]]=max(dp[i][pi[j-1]], dp[i][j]);
        }
    }
    int maxi=0;
    for (int i=0; i<m; i++) {
        maxi=max(maxi, dp[n][i]);
    }
    cout << maxi << "\n";
    return 0;
}