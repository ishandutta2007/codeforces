#include <bits/stdc++.h>

using namespace std;
const int c=3005;
int w, n, t[3005], dp[c][c];
bool v[c][c];
vector<int> sz[c];

int solve(int a, int b) {
    if (a>=b) {
        return 0;
    }
    if (!v[a][b]) {
        int maxi=solve(a+1, b);
        for (int x:sz[t[a]]) {
            if (x>a && x<b) {
                maxi=max(maxi, solve(a, x)+solve(x+1, b));
            }
        }
        if (t[a]==t[b]) {
            maxi++;
        }
        v[a][b]=1;
        dp[a][b]=maxi;
    }
    return dp[a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sz[t[i]].push_back(i);
        }
        cout << n-1-solve(1, n) << "\n";

        for (int i=1; i<=n; i++) {
            sz[i].clear(), t[i]=0;
            for (int j=1; j<=n; j++) {
                dp[i][j]=0, v[i][j]=0;
            }
        }

    }
    return 0;
}