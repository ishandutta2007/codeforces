#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long mod=998244353, dp[c][3], ps[c];
bool v[c];
int n;
vector<int> sz[c];
void dfs(int a) {
    v[a]=1;
    long long f=0, db=1, sum=1, si=sz[a].size(), p=0;
    for (int i=0; i<si; i++) {
        int x=sz[a][i];
        if (v[x]) f=x, ps[x]=db;
        else {
            dfs(x);
            ps[x]=db;
            db*=dp[x][0]+dp[x][1], db%=mod;
        }
    }
    dp[a][2]+=db;
    for (int i=si-1; i>=0; i--) {
        long long x=sz[a][i], y=sum*ps[x]%mod;
        if (x==f) dp[a][1]=y, p=1;
        else {
            if (!p) dp[a][2]+=y*dp[x][2], dp[a][2]%=mod;
            else dp[a][0]+=y*dp[x][2], dp[a][0]%=mod;
            sum*=dp[x][0]+dp[x][2], sum%=mod;
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    sz[0].push_back(1), sz[1].push_back(0);
    dfs(0);
    cout << (dp[1][0]+dp[1][1])%mod << "\n";
    return 0;
}