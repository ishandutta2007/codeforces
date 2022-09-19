#include <bits/stdc++.h>

using namespace std;
long long n, dp[300002][3], mod=998244353;
vector<long long> sz[300002];
bool v[300002];
void dfs(long long a) {
    v[a]=true;
    long long p=1, r=1, m=1;
    for (long long i=0; i<sz[a].size(); i++) {
        long long x=sz[a][i];
        if (!v[x]) {
            dfs(x);
            long long aa=dp[x][0], bb=dp[x][1], cc=dp[x][2], sum=(aa+bb+cc)%mod;
            p*=sum, p%=mod;
            r*=(aa+bb)%mod, r%=mod;
            m*=aa, m%=mod;
        }
    }
    dp[a][0]=(p+r-m+mod)%mod;
    dp[a][1]=p;
    dp[a][2]=r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<n; i++) {
        long long a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << dp[1][0]-1 << "\n";
    return 0;
}