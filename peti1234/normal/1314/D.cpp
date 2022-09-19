#include <bits/stdc++.h>

using namespace std;
int n, k, mini=INT_MAX;
int t[81][81], dp[81][10];
bool v[81];
vector<int> x, y;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> t[i][j];
    for (int i=1; i<=n; i++) dp[i][1]=t[i][1];
    for (int p=1; p<=10000; p++) {
        x.clear(), y.clear();
        for (int i=1; i<=n; i++) for (int j=2; j<=k; j++) dp[i][j]=INT_MAX;
        for (int i=2; i<=n; i++) {
            int x=rand();
            v[i]=x%2;
        }
        for (int i=1; i<=n; i++) {
            if (v[i]) x.push_back(i);
            else y.push_back(i);
        }
        if (x.size()==0 || y.size()==0) continue;
        for (int i=2; i<=k; i++) {
            for (int a=0; a<x.size(); a++) {
                for (int b=0; b<y.size(); b++) {
                    int p=x[a], q=y[b];
                    dp[p][i]=min(dp[p][i], dp[q][i-1]+t[p][q]);
                    dp[q][i]=min(dp[q][i], dp[p][i-1]+t[q][p]);
                }
            }
        }
        mini=min(mini, dp[1][k]);
    }
    cout << mini << endl;
    return 0;
}