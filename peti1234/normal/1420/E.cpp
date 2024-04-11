#include <bits/stdc++.h>

using namespace std;
const int c=82;
int n, dp[c][c*c][c], db, k, si;
bool v[c];
vector<int> sz;
int main()
{
    cin >> n, k=n*(n-1)/2;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        if (!v[i]) db++;
        else sz.push_back(i), si++;
    }
    for (int i=0; i<=k; i++) for (int j=1; j<=n+1; j++) {
        dp[0][i][j]=(j-1)*(j-1);
        for (int t=1; t<=si; t++) dp[t][i][j]=c*c;
    }
    for (int i=1; i<=si; i++) for (int pos=i+1; pos<=n+1; pos++) for (int h=i; h<pos; h++) for (int st=abs(sz[i-1]-h); st<=k; st++) dp[i][st][pos]=min(dp[i][st][pos], (pos-h-1)*(pos-h-1)+dp[i-1][st-abs(sz[i-1]-h)][h]);
    for (int i=0; i<=k; i++) cout << (db*db-dp[si][i][n+1])/2 << " ";
    return 0;
}