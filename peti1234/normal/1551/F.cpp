#include <bits/stdc++.h>

using namespace std;
const int c=105;
long long mod=1e9+7, dp[c][c];
int w, n, k, szint[c], cnt[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    cnt[szint[a]]++;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
        }
    }
}
long long solve(int a) {
    v[a]=true;
    for (int i=1; i<=n; i++) {
        dp[i][0]=1;
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=1;
            dfs(x);
        }

        for (int i=1; i<=n; i++) {
            for (int j=n; j>=1; j--) {
                dp[i][j]=(dp[i][j-1]*cnt[i]+dp[i][j])%mod;
            }
            cnt[i]=0;
        }
    }
    long long sum=0;
    for (int i=1; i<=n; i++) {
        v[i]=0, szint[i]=0;
        sum=(sum+dp[i][k])%mod;
        for (int j=1; j<=n; j++) {
            dp[i][j]=0;
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        if (k==2) {
            cout << n*(n-1)/2 << "\n";
        } else {
            long long sum=0;
            for (int i=1; i<=n; i++) {
                sum+=solve(i);
                sum%=mod;
            }
            cout << sum << "\n";
        }

        for (int i=1; i<=n; i++) {
            sz[i].clear();
        }
    }
    return 0;
}