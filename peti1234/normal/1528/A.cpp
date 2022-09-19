#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long kis[c], nagy[c], dp[c][2];
int w, n;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    long long kk=0, nn=0;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            kk+=max(abs(kis[a]-kis[x])+dp[x][0], abs(kis[a]-nagy[x])+dp[x][1]);
            nn+=max(abs(nagy[a]-kis[x])+dp[x][0], abs(nagy[a]-nagy[x])+dp[x][1]);
        }
    }
    dp[a][0]=kk, dp[a][1]=nn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> kis[i] >> nagy[i];
        }
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        cout << max(dp[1][0], dp[1][1]) << "\n";
        for (int i=1; i<=n; i++) {
            kis[i]=0, nagy[i]=0;
            dp[i][0]=0, dp[i][1]=1;
            sz[i].clear();
            v[i]=0;
        }
    }
    return 0;
}