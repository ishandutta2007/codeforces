#include <bits/stdc++.h>

using namespace std;
const int c=4005;
long long n, m, t[c], fel[c], dp[c][c], rf[c];
vector<int> sz[c];
void solve(int a, int b, int c) {
    if (a>b) {
        return;
    }
    int pos=a;
    for (int i=a; i<=b; i++) {
        if (t[i]<t[pos]) {
            pos=i;
        }
    }
    sz[c].push_back(pos);
    fel[pos]=c;
    solve(a, pos-1, pos), solve(pos+1, b, pos);
}
void dfs(int a) {
    rf[a]=1;
    for (auto x:sz[a]) {
        dfs(x);
        for (int i=rf[a]; i>=0; i--) {
            for (int j=rf[x]; j>=0; j--) {
                dp[a][i+j]=max(dp[a][i+j], dp[a][i]+dp[x][j]+j*(m-j)*(t[x]-t[a]));
            }
        }
        rf[a]+=rf[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    solve(1, n, 0);
    int st=sz[0][0];
    dfs(st);
    cout << dp[st][m] << "\n";
    return 0;
}