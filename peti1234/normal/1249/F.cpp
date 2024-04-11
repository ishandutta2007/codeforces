#include <bits/stdc++.h>

using namespace std;
const int c=202;
int n, m, t[c], dp[c][c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    int f=-1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            dp[a][0]+=dp[x][m];
        }
        else f=i;
    }
    //cout << "alap " << a << " " << dp[a][0] << endl;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<sz[a].size(); j++) {
            if (f!=j) {
                int sum=dp[sz[a][j]][i-1];
                for (int k=0; k<sz[a].size(); k++) {
                    if (k!=f && k!=j) sum+=dp[sz[a][k]][max(i-1, m-i)];
                }
                dp[a][i]=max(dp[a][i], sum);
            }
        }
    }
    for (int i=m; i>=0; i--) {
        dp[a][i]=max(dp[a][i], dp[a][i+1]);
        //cout << "res " << a << " " << i << " " << dp[a][i] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> dp[i][0];
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << dp[1][0];
    return 0;
}
/*
5 1
1 2 3 4 5
1 2
2 3
3 4
3 5
*/