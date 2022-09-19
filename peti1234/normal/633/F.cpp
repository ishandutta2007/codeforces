#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, ert[c], dp[c][5];
vector<int> sz[c];
bool v[c];
void dfs(int i) {
    v[i]=true;
    for (int x:sz[i]) {
        if (!v[x]) {
            dfs(x);
            dp[i][4]=max({dp[i][4], dp[i][1]+dp[x][3]+ert[i], dp[i][2]+dp[x][2], dp[i][0]+dp[x][2]+ert[i], dp[i][3]+dp[x][1]+ert[i], dp[x][4]});
            dp[i][3]=max({dp[i][3], dp[i][2]+dp[x][1], dp[i][1]+dp[x][2], dp[x][3]});
            dp[i][2]=max(dp[i][2], dp[x][2]);
            dp[i][0]=max(dp[i][0], dp[i][1]+dp[x][1]);
            dp[i][1]=max(dp[i][1], dp[x][1]);
        }
    }
    dp[i][0]+=ert[i], dp[i][1]+=ert[i], dp[i][3]+=ert[i];
    dp[i][2]=max(dp[i][2], dp[i][0]);
    for (int j=2; j<=4; j++) dp[i][j]=max(dp[i][j], dp[i][j-1]);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> ert[i];
    for (int i=1; i<n; i++) {
        int x, y; cin >> x >> y;
        sz[x].push_back(y), sz[y].push_back(x);
    }
    dfs(1);
    cout << dp[1][4] << "\n";
    return 0;
}