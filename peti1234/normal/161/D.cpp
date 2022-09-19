#include <bits/stdc++.h>

using namespace std;
const int c=50002;
int n, k, dp[c][502], sum;
bool v[c];
vector<int> sz[c];
void dfs(int a) {
    v[a]=true, dp[a][0]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            for (int i=0; i<k; i++) sum+=dp[x][i]*dp[a][k-i-1];
            for (int i=0; i<k; i++) dp[a][i+1]+=dp[x][i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << sum << "\n";
    return 0;
}