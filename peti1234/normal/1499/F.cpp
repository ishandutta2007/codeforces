#include <bits/stdc++.h>

using namespace std;
const int c=5001;
long long n, k, mod=998244353, o=0;
int dp[c][c], kom[c][c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    dp[a][0]=1;
    for (int i=0; i<=k; i++) {
        kom[a][i]=1;
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            for (long long i=k; i>=0; i--) {
                long long kis=kom[x][k], nagy=0;
                int s=min(i-1, k-i-1);
                if (s>=0) {
                    kis+=kom[x][s];
                }
                s=min(i-1, k-i);
                nagy+=kom[a][s];
                dp[a][i]=(dp[a][i]*kis+dp[x][i-1]*nagy)%mod;
            }
            kom[a][0]=dp[a][0];
            for (int i=1; i<=k; i++) {
                kom[a][i]=(kom[a][i-1]+dp[a][i])%mod;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << kom[1][k] << "\n";
    return 0;
}
/*
2 1
1 2
*/