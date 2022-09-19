#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, dp[c][3], mod=998244353;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    dp[a][0]=1;
    if (sz[a].size()==0) {
        dp[a][1]=1;
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            long long a0=dp[a][0], a1=dp[a][1], a2=dp[a][2], x0=dp[x][0], x1=dp[x][1];
            dp[a][0]=(a0*x0)%mod;
            dp[a][1]=(a0*x1+a1*x0+a1*x1)%mod;
            dp[a][2]=(a1*x1+a2*x0)%mod;
        }
    }
    dp[a][0]+=dp[a][2];
    dp[a][0]%=mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=2; i<=n; i++) {
        int x; cin >> x;
        sz[x].push_back(i);
    }
    dfs(1);
    cout << dp[1][0]<< "\n";
    return 0;
}